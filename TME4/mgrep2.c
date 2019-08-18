#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXFILS 3

int main(int argc , char *argv[]){
	int nbFils =argc -2;
	int i ;
	int res;
	if(nbFils < MAXFILS){
		for(i =0; i<nbFils; i++){
			res = fork();

			if(res == 0 ){
				execlp("grep","grep",argv[1], argv[i+2],NULL);
				break;		
			}
		}
		if(res != 0){
			for (i = 0 ; i<nbFils ;i++){	
				wait(NULL);
			}	
		}
	

	}else{
		for(i =0; i<MAXFILS; i++){
			res = fork();
			//printf("%d res \n",res);
			//printf("%d i du premier for \n\n",i);
			if(res == 0 ){
				execlp("grep","grep",argv[1], argv[i+2],NULL);
				break;		
			}
		}

		if(res != 0){
			for (i = MAXFILS ; i<nbFils ;i++){	
				wait(NULL);
				res = fork();
				//printf("%d i du 2eme for \n",i);
				
				if(res == 0 ){
					//printf("proc mort on creer un nouveau \n\n");
					execlp("grep","grep",argv[1], argv[i+2],NULL);
					break;		
				}
			}	
		}

		if(res != 0){
			for (i = 0 ; i<MAXFILS ;i++){	
				wait(NULL);
		}	
	}
	
		
	}


	
	return 0;
}
