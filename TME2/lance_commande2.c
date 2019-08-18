#include <stdlib.h>
#include <stdio.h>
#include <sys/times.h>
#include <unistd.h> 
#include <limits.h> 

#define TICK (double) sysconf(_SC_CLK_TCK)

void lance_commande(char * commande ){
	if(system(commande) == -1){
		printf("Erreur de commande\n");
		exit(0);
	}

}


int main (int argc, char *argv[]){
	int i;
	struct tms buf1, buf2; 

	clock_t sinceboot1, sinceboot2; 

	for(i = 1; i<argc ; i++){

		sinceboot1 = times(&buf1); 

		lance_commande(argv[i]);

		sinceboot2 = times(&buf2); 

		printf("Statistiques de %s: \n", argv[i] );
		//clock_t times(struct tms *buf); 
		printf("Temps total : %f \n", (sinceboot2 - sinceboot1 ) /TICK); 
   		printf("Temps utilisateur : %f \n", (buf2.tms_utime - buf1.tms_utime) / TICK); 
		printf("Temps systeme  : %f \n", (buf2.tms_stime - buf1.tms_stime) / TICK); 
		printf("Temps utilisateur fils: %f \n", (buf2.tms_cutime - buf1.tms_cutime) / TICK); 
		printf("Temps systeme fils : %f \n", (buf2.tms_cstime - buf1.tms_cstime) / TICK); 
		printf("\n");

	}

	return 0;
}
