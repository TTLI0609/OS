#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){
	char str[50];

 	char *token;
	const char s[2] = " ";

	char *c[50];
	int i=0;

	while(1){
		printf("Enter une commande : ");
		fgets(str, sizeof str, stdin);

		token = strtok(str, s);
		 while( token != NULL ) {
    			c[i]=token;
			i++;
			printf("%s",token);
     			token = strtok(NULL, s);
   		}
		c[i]="NULL";

		if(strcmp(str,"quit") ==0 ){
			printf("On sort.\n ");
			break;
		}

		if(fork() ==0){

			execvp(c[0],&c);
			exit(1);
		}
		if( c[strlen(c)-1] != '&')
			wait(NULL);

	}

	return 0;
}
