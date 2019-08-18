#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <sched.h>

#define LONGTIME 8E8
void ProcLong(int *);
void ProcCourt(int *);

// Exemple de processus long (une simple bouble),
// Chaque processus long crée a son tour 4 processus courts
//
void ProcLong(int *pid) {
  long i;
  static int cpt = 0;

  for (i=0;i<LONGTIME;i++) {
    if (i%(long)(LONGTIME/4) == 0)  {
      int *tcpt = (int *) malloc(sizeof(int));
      *tcpt = cpt;
      CreateProc((function_t)ProcCourt,(void *)tcpt, 10);
      cpt++;
    }
    if (i%(long)(LONGTIME/100) == 0)
      printf("Proc. Long %d - %ld\n",*pid, i);
  }
  printf("############ FIN LONG %d\n\n", *pid );
}


// Processus court
void ProcCourt(int *pid) {
  long i;

  for (i=0;i<LONGTIME/10;i++)
    if (i%(long)(LONGTIME/100) == 0)
      printf("Proc. Court %d - %ld\n",*pid, i);
  printf("############ FIN COURT %d\n\n", *pid );
}




// Exemples de primitive d'election definie par l'utilisateur
// Remarques : les primitives d'election sont appelées directement
//             depuis la librairie. Elles ne sont appélées que si au
//             moins un processus est à l'etat pret (RUN)
//             Ces primitives manipulent la table globale des processus
//             définie dans sched.h


// Election aléatoire
int RandomElect(void) {
  int i;

  printf("RANDOM Election !\n");

  do {
    i = (int) ((float)MAXPROC*rand()/(RAND_MAX+1.0));
  } while (Tproc[i].flag != RUN);

  return i;
}


// Election de SJF "Shortest Job Fisrt"
int SJFElect(void) {
  int p=0;
  double duration_min;
  int i;
  
	printf("SJF Election !\n");
	
	for(i=0;i<MAXPROC ; i++){
		if(Tproc[i].flag == RUN){
			duration_min = Tproc[i].duration;
			p=i;
			break;
		}
	}
	
	for(i = 0;i<MAXPROC ; i++){
		if(duration_min>Tproc[i].duration && Tproc[i].flag == RUN){
			duration_min = Tproc[i].duration;
			p=i;
		}
	}



  return p;	
}



// Approximation SJF
int ApproxSJF(void) {
  int p;
  double ncpu_min;
  int i;
  
	printf("ApproxSJF Election !\n");
	
	for(i=0;i<MAXPROC ; i++){
		if(Tproc[i].flag == RUN){
			ncpu_min = Tproc[i].ncpu;
			p=i;
			break;
		}
	}
	
	for(i = 0;i<MAXPROC ; i++){
		if(ncpu_min>Tproc[i].ncpu && Tproc[i].flag == RUN){
			ncpu_min = Tproc[i].ncpu;
			p=i;
		}
	}


  return p;
}


//on augment la priorité du processus le plus ancient
int ApproxSJF2(void) {
	int p;
  double ncpu_min;
  int i;
  int p2;
  int p3;
  
	printf("ApproxSJF2 Election !\n");
	
	for(i=0;i<MAXPROC ; i++){
		if(Tproc[i].flag == RUN){
			ncpu_min = Tproc[i].ncpu;
			p=i;
			break;
		}
	}
	
	p2=p;
	p3 = p;
	
	for(i = 0;i<MAXPROC ; i++){
		if(Tproc[p2].prio<Tproc[i].prio && Tproc[i].flag == RUN){
			p2=i;
		}
		if(ncpu_min>Tproc[i].ncpu && Tproc[i].flag == RUN){
			ncpu_min = Tproc[i].ncpu;
			p=i;
		}
		if(Tproc[p3].start_time.tv_sec>Tproc[i].start_time.tv_sec && Tproc[i].flag == RUN){
			p3=i;
		}
	}
	
		if(Tproc[p3].prio<MAXPRIO)
			Tproc[p3].prio++;
	
		if(p2==p){
			return p;
		}else{
			return p2;
		}

}

//on decremente la priorité du processus élu
int ApproxSJF3(void) {


  int p;
  double ncpu_min;
  int i;
  
	printf("ApproxSJF Election !\n");
	
	for(i=0;i<MAXPROC ; i++){
		if(Tproc[i].flag == RUN){
			ncpu_min = Tproc[i].ncpu;
			p=i;
			break;
		}
	}
	
	for(i = 0;i<MAXPROC ; i++){
		if(ncpu_min>Tproc[i].ncpu && Tproc[i].flag == RUN){
			ncpu_min = Tproc[i].ncpu;
			p=i;
		}
	}

	if(Tproc[p].prio > MINPRIO)
		Tproc[p].prio--;

  return p;

}


int main (int argc, char *argv[]) {
  int i;
  int *j;  

  // Créer les processus long
  for  (i = 0; i < 2; i++) {
    j = (int *) malloc(sizeof(int));
    *j= i;
    CreateProc((function_t)ProcLong,(void *)j, 80);
  }



  // Definir une nouvelle primitive d'election avec un quantum de 1 seconde
  SchedParam(NEW, 0.3, ApproxSJF3);

  // Lancer l'ordonnanceur en mode non "verbeux"
  sched(0);     

  // Imprimer les statistiques
  PrintStat();

  return EXIT_SUCCESS;

}
