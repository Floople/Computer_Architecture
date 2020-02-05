all: main

main: first.c
	gcc -Wall -Werror -fsanitize=address -std=c99 -lm -g first.c -o first

clean:
	rm -rf first

