cards: cards.o
	gcc cards.o -o cards
cards.o: cards.c
	gcc -c cards.c -o cards.o

.PHONY: run
run:
	gcc cards.c -o cards && ./cards

.PHONY: clean
clean :
	rm -f cards cards.o
