all:
	gcc main.c -L. -lkirian -o main
	./main

compile:
	gcc -c kirian.c -o kirian.o
	ar rc libkirian.a kirian.o
	