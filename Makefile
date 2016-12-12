build: numbers

numbers: main.o
	gcc main.o -o numbers-to-text -lncurses

install:
	sudo apt-get install libncurses-dev

main.o: main.c
	gcc -c main.c

clean:
	rm -rf main.o

run:
	./numbers-to-text
