#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc , char *argv[]){
printf("1\n");
	int res = fork();

	if(res != 0){
		int res=fork();
	}
	
	if(res==0){
		exit(1);
	}
	if(res!=0){
		sleep(10);
	}
	wait(NULL);
	wait(NULL);

}
