CC=gcc
CFLAGS=-ffreestanding -nostartfiles -static -Os -s

http_exec: http_exec.c
	$(CC) $(CFLAGS) -o http_exec http_exec.c

clean:
	rm http_exec || true
