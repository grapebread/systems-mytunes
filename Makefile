all: main.o linkedlist.o
	gcc -o mytunes main.o linkedlist.o

main.o: main.c linkedlist.h
	gcc -c main.c

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

run:
	@./mytunes

clean:
	-rm *.o
	-rm *~
	-rm *.exe
	-rm mytunes
