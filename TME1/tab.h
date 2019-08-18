#ifndef TAB_H_INCLUDED
#define TAB_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#define NMAX 1000000

void InitTab(int *tab, int size);

void PrintTab(int * tab, int size);

int Sum_Tab(int *tab, int size);

int MinSum_Tab(int *min, int *tab, int size);

#endif // TAB_H_INCLUDED
