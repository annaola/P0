main : main.c
	gcc -pthread -Wall -Werror main.c -o main

.PHONY: run

run:
	./main 
