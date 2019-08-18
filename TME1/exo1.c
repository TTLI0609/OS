#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	int i;
	int res=atoi(argv[1]);

	for (i=2;i<argc;i++){
		if(atoi(argv[i])>res){
			res=atoi(argv[i]);
		}
	}
	printf("Le maximun de cette chaine est : %d\n\n",res);
	return 0;
}
