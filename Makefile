exec: main.o
	gcc -Wall -O2 -o lambda main.o

main.o: main.c
	gcc -c main.c