#include <stdio.h>
#include "affiche_tas.h"
#include <ctype.h>

void afficher_tas(){
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 16; j++) { 
	    printf("%4d", j + 16*i);
        }
        printf("\n");
        for (j = 0; j < 16; j++) { 
	    printf("%4d", tas[j + 16*i]);
        }
        printf("\n");
        for (j = 0; j < 16; j++) { 
	    if (isalnum(tas[j + 16*i])) {
	        printf("%4c", tas[j + 16*i]);
	    } else {
		printf("    ");
	    }
        }
        printf("\n\n");
    }
    printf("---------------------------------------------------------------\n\n");
}

void tas_init(){
  libre = 0;
  tas[0] = TAILTAS;
  tas[1] = -1;
}

int first_fit (int taille, int *pred){
/*
	 int l=libre;
	 int lp;
	 lp=l;
	 if(tas[l]>=taille){	//1ere case 
	 	pred=&l;
	 	return l;	
	 	
	 }	
	 l=tas[l+1];
	 	
	 while(tas[l]<taille){
	 	lp=l;
	 	l=tas[l+1];
	 	if(tas[l]<taille && tas[l+1]==-1){
	 		return -1;
	 	}
	}
	
	pred=&lp;
	return l;
	*/

	int p = libre;
	while(p != -1 && tas[p]<taille){
		*pred = p;
		p = tas[p+1];
	}
	return p;

}

char* tas_malloc (int taille){
	int prec, l;
	l =  first_fit(taille, &prec);
	
	if(l==-1)
		return NULL;
		
	
	
	if(libre != l){	//on a un preceddent et suivant
		if(taille < tas[l]-2){	//s'il y a au moins 2 case libre
			
			
			tas[l+taille+1] = tas[l] -taille -1 ; //la taille de la nouvelle zone libre 
			tas[l +taille +2] =tas[l+1];	//nouvelle zone libre pointe vers suivant
			prec = tas[l+taille+1];		//prec pointe vers la nouvelle zone libre 
			
			tas[l]=taille; //on change la valeur pour la zone nouvellement alloué
		}
		else{ //miette : on va allouer taille+1 cases
			//pas de nouvelle zone libre
			prec = tas[l+1]; //prec pointe vers suivant
			tas[l]=taille; //on change la valeur pour la zone nouvellement alloué
		}
	
	}else{	//1ere case
		if(taille < tas[l]-2){	//s'il y a au moins 2 case libre
			
			tas[l+taille+1] = tas[l] -taille -1 ; //la taille de la nouvelle zone libre 
			tas[l +taille +2] =tas[l+1];	//nouvelle zone libre pointe vers suivant
			//vu que c'est la 1ere emplacement libre on a pas de prec
			tas[l]=taille; //on change la valeur pour la zone nouvellement alloué

			libre =l+taille+1;
		}		
		else{ //miette on va allouer taille+1 cases
			//pas de nouvelle zone libre
			//pas de prec
			tas[l]=taille; //on change la valeur pour la zone nouvellement alloué
			libre = l+taille+1;
		}


	}
	
	
	return (char *)&tas[l+1];
	
	
	
	
}





void tas_free( char * proc){
	int l  = *(proc-1);
	printf("l = %d\n",l);
	printf("l = %d\n",*(proc+l));

}

