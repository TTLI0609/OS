#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>


void lance_commande(char * commande ){
	if(system(commande) == -1){
		printf("Erreur de commande\n");
		exit(0);
	}

}


int main (int argc, char *argv[]){
	int i;
	struct timeval temps_avant , temps_apres;
	for(i = 1; i<argc ; i++){
		gettimeofday(&temps_avant,NULL);
		lance_commande(argv[i]);
		gettimeofday(&temps_apres,NULL);
		printf("temps en us: %ld \n", ((temps_apres.tv_sec - temps_avant.tv_sec) * 1000000 + temps_apres.tv_usec) - temps_avant.tv_usec);
	}

	return 0;
}
