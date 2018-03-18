# compilateur
CC = gcc
#options
CFLAGS = -Wall -Wextra -g -O2
LDFLAGS = -lm

#liste des fichiers objets
OBJ = main.o Pile.o File.o

#règle de production finale
prog : $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o prog

#règle de production pour chaque fichier
main.o : main.c Pile.o File.o
	$(CC) -c main.c $(CFLAGS)

Pile.o : Pile.c
	$(CC) -c Pile.c $(CFLAGS)

File.o : File.c
	$(CC) -c File.c $(CFLAGS)

clean :
	rm -f *.o
