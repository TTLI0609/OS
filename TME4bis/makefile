all: main mini_shell mini_shell2

main: exo1.o main.o
	gcc -o main exo1.o main.o

exo1.o: exo1.c 
	gcc -o exo1.o -c exo1.c -Wall 

main.o: main.c exo1.h
	gcc -o main.o -c main.c -Wall 

mini_shell : saisie_cmd.o 
	gcc -o mini_shell saisie_cmd.o 

saisie_cmd.o : saisie_cmd.c
	gcc -o saisie_cmd.o -c saisie_cmd.c -Wall 

mini_shell2 : saisie_cmd2.o 
	gcc -o mini_shell2 saisie_cmd2.o 

saisie_cmd2.o : saisie_cmd2.c
	gcc -o saisie_cmd2.o -c saisie_cmd2.c -Wall 

clean:
	rm -rf *.o main mini_shell mini_shell2
