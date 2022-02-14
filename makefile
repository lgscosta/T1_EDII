# # Makefile Luana Costa

all: main

main: basics.o heapsort.o insertionsort.o list.o main.o quicksort.o selectionsort.o shellsort.o stats.o
	gcc -o main basics.o heapsort.o insertionsort.o list.o main.o quicksort.o selectionsort.o shellsort.o stats.o -g -Wall

main.o: main.c
	gcc -c main.c

basics.o: basics.c
	gcc -c basics.c

list.o: list.c
	gcc -c list.c

stats.o: stats.c
	gcc -c stats.c

selectionsort.o: selectionsort.c
	gcc -c selectionsort.c

insertionsort.o: insertionsort.c
	gcc -c insertionsort.c

shellsort.o: shellsort.c
	gcc -c shellsort.c

quicksort.o: quicksort.c
	gcc -c quicksort.c

heapsort.o: heapsort.c
	gcc -c heapsort.c

clean: 
	rm -rf main

rmproper: clean
	rm -rf main

run: main
	./main -123h 5 ./aleatorio1/100000.txt