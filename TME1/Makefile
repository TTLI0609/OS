all: main

main: tab.o maintab.o
	gcc -o main tab.o maintab.o

tab.o: tab.c
	gcc -o tab.o -c tab.c -Wall 

maintab.o: maintab.c tab.h
	gcc -o maintab.o -c maintab.c -Wall 


clean:
	rm -rf *.o main
