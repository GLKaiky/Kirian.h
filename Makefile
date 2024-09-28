all:
	gcc src/main.c -Llib -lkirian -o src/main
	src/main
compile:
	gcc -c lib/kirian.c -o lib/kirian.o
	ar rc lib/libkirian.a lib/kirian.o
