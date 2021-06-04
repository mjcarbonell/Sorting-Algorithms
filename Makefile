CC = clang 
CFLAGS = -Wall -Wextra -Werror -Wpedantic 

all: sorting 

sorting: sorting.o bubble.o shell.o quick.o stack.o queue.o
	$(CC) -o sorting sorting.o bubble.o shell.o quick.o stack.o queue.o -lm
bubble.o: bubble.c
	$(CC) $(CFLAGS) -c bubble.c 
shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c
quick.o: quick.c
	$(CC) $(CFLAGS) -c quick.c
stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c
queue.o: queue.c
	$(CC) $(CFLAGS) -c queue.c
sorting.o: sorting.c
	$(CC) $(CFLAGS) -c sorting.c
clean:
	rm -f sorting sorting.o bubble.o shell.o quick.o 

scan-build: clean
	scan-build make   
	
format: 
	clang-format -i -style=file bubble.c shell.c quick.c stack.c queue.c sorting.c 
