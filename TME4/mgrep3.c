#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>


int main(int argc , char *argv[]){
	int nbFils =argc -2;
	int i ;
	int res;

	struct rusage  r;

	for(i =0; i<nbFils; i++){
		res = fork();

		if(res == 0 ){
			execlp("grep","grep",argv[1], argv[i+2],NULL);
			break;		
		}
	}
	
	
	if(res != 0){
		for (i = 0 ; i<nbFils ;i++){	
			wait3(NULL,0,&r);
			printf("Le temps d'utilisation en user du fils %d est : %ld\n",i, ((r.ru_utime.tv_sec - r.ru_utime.tv_sec) * 1000000 + r.ru_utime.tv_usec) - r.ru_utime.tv_usec);
			printf("Le temps d'utilisation en system du fils %d est : %ld\n",i, ((r.ru_utime.tv_sec - r.ru_utime.tv_sec) * 1000000 + r.ru_utime.tv_usec) - r.ru_utime.tv_usec);
		}	
	}
	return 0;
}

