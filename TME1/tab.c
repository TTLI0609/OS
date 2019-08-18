#include "tab.h"


void InitTab(int *tab, int size){
	srand(time(NULL));

	int i;
	for (i=0;i<size;i++){
		tab[i]= rand()%10;
	}
	return;
}

void PrintTab(int * tab, int size){
	int i; 
	for(i=0; i<size; i++){
		printf("%d ", tab[i]);
	}
	return;
}


int Sum_Tab(int *tab, int size){
	int S=0;
	int i;
	for(i=0; i<size; i++){
		S+=tab[i];
	}
	return S;
}

int MinSum_Tab(int *min, int *tab, int size){
	int S=0;
	int i;
	int min2=10;
	for(i=0; i<size; i++){
		S+=tab[i];
		if(min2>tab[i]){
			min2=tab[i];
		} 
	}
	*min=min2;
	return S;
}
		


