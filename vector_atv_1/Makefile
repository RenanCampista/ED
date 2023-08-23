all:
	gcc -Wall -g -o main *.c
clean:
	rm -f main
valgrind:
	valgrind --track-origins=yes --leak-check=full ./main
