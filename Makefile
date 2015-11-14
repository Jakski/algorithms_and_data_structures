CC = gcc
CCFLAGS = -Wall -std=c99

%:
	$(CC) $(CCFLAGS) $@.c -o $@.out
	./$@.out

clean:
	rm -f `find ./ -name "*.out"`
