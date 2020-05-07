CC=gcc
CFLAGS=-ffreestanding -nostartfiles -static -Os -s

mget: mget.c
	$(CC) $(CFLAGS) -o mget mget.c

clean:
	rm mget || true
