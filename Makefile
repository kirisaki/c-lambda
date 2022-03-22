exec: main.o
	gcc -Wall -O2 -o lambda main.o

main.o: main.c
	gcc -std=c99 -c main.c