#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc , char *argv[]){
	int nbFils =argc -2;
	int i ;
	int res;
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
	return 0;
}
