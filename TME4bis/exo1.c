#include "exo1.h"


void arbreN(int L){
	int p1 = 0;
	int p2 = 0;
	int i =0;	

	printf("%d\n",getpid());
	while ( (i < L) && (((p1=fork()) ==0) || ((p2=fork()) ==0)) ){
		i++;
		printf("%d\n",i);	
	}
	sleep(30);
	if(i<L){
		wait(NULL);
		printf("un fils fini = %d\n",i);
	}
}
