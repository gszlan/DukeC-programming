CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99


test-future: deck.o eval.o test-future.o cards.o future.o input.o
	gcc -o test-future $(CFLAGS) deck.o eval.o test-future.o cards.o input.o future.o

test-future.o: test-future.c
	gcc -c test-future.c $(CFLAGS)

deck.o: deck.c
	gcc -c deck.c $(CFLAGS) 

eval.o: eval.c
	gcc -c eval.c $(CFLAGS)

cards.o: cards.c
	gcc -c cards.c $(CFLAGS)

future.o: future.c
	gcc -c future.c $(CFLAGS)

input.o: input.c
	gcc -c input.c $(CFLAGS)

clean:
	rm -f cards.o test-future.o deck.o future.o eval.o test-future input.o *~
