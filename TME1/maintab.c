#include "tab.h"


void PrintMem (){
	struct rusage usage;
	getrusage(RUSAGE_SELF, &usage);
	printf("%ld", usage.ru_maxrss);
	return;
}


int main(int argc, char *argv[]){
	printf("	Mémoire résidente occupée par le program au début :  "); PrintMem () ;
	printf("\n");

	int tab [NMAX];
	InitTab(tab,NMAX);
	printf("	Mémoire résidente occupée par le program apres le init :  "); PrintMem () ;
	printf("\n");
	//PrintTab(tab, NMAX);

	printf("\nTest Sum_Tab :  ");
	printf("%d",Sum_Tab(tab,NMAX));

	printf("\nTest MinSum_Tab:  ");
	int *min=malloc(sizeof(int));
	printf("%d",MinSum_Tab(min, tab, NMAX));
	printf("\n");
	printf("Le min de ce tableau est : %d", *min);
	printf("\n");
	printf("	Mémoire résidente occupée par le program à la fin :  "); PrintMem () ;
	printf("\n");

	printf("\n\n");
	printf("Tableau avec malloc :\n");
	printf("	Mémoire résidente occupée par le program au début :  "); PrintMem () ;
	int * tab2 = malloc(sizeof(int)*NMAX);
	printf("\n");
	InitTab(tab2,NMAX);
	printf("	Mémoire résidente occupée par le program apres le init :  "); PrintMem () ;
	printf("\n");
	//PrintTab(tab2, NMAX);
	printf("\nTest Sum_Tab :  ");
	printf("%d",Sum_Tab(tab,NMAX));

	printf("\nTest MinSum_Tab:  ");
	printf("%d",MinSum_Tab(min, tab2, NMAX));
	printf("\n");
	printf("Le min de ce tableau est : %d", *min);
	printf("\n");
	printf("	Mémoire résidente occupée par le program à la fin :  "); PrintMem () ;
	printf("\n");

}




