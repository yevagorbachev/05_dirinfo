ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

objects = main.o llist.o

all: $(objects)
	$(CC) -o program $(objects)

main.o: main.c llist.c
	$(CC) -c main.c

llist.o: llist.c
	$(CC) -c llist.c

leak:
	valgrind --leak-check=yes ./program

run:
	./program

clean:
	rm *.o