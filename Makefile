main: main.o htags.o
	gcc -o main main.o htags.o

htags.o: htags.c
	gcc -c htags.c

main.o: main.c
	gcc -c main.c

clean:
	rm htags.o main.o main