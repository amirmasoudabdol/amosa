CFLAGS=-I/usr/include/malloc

all:
	gcc $(CFLAGS) -O2 -lm amosa_real.c -o amosa

clean:
	rm amosa