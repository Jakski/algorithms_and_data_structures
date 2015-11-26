CC = gcc
CCFLAGS = -Wall -std=c99 -g

%:
	$(CC) $(CCFLAGS) $@.c -o $@.out
	./$@.out

clean:
	rm -f `find ./ -name "*.out"`
