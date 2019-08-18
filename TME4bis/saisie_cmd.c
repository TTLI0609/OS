#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){
	char str[50];

	while(1){
		printf("Enter une commande : ");
		fgets(str, sizeof str, stdin);

		if(strcmp(str,"quit") ==0 ){
			printf("On sort.\n ");
			break;
		}
		char tmp = str[strlen(str)-2];
		if(fork() ==0){
			
			str[strlen(str)-1]=0;
			if( str[strlen(str)-1] == '&'){
				str[strlen(str)-1]=0;
				str[strlen(str)-1]=0;
			}
			execlp(str,str,NULL);
			exit(1);
		}
		if( tmp != '&')
			wait(NULL);

	}

	return 0;
}
