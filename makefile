main.o: main.c
	gcc -c main.c -lm

liste_chainee.o: liste_chainee.c proto.h
	gcc -c liste_chainee.c -lm

graph.o: graph.c proto.h
	gcc -c graph.c -lm

projet: main.c liste_chainee.o graph.o
	gcc main.c liste_chainee.o graph.o -lm -o projet -g