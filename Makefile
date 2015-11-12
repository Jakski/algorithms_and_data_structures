CC = gcc
CCFLAGS = -Wall

%:
	$(CC) $@.c -o $@.out
	./$@.out

clean:
	rm -f `find ./ -name "*.out"`
