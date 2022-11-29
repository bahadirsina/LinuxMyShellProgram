all: Myshell

Myshell: Myshell.c
	gcc Myshell.c -o myshell
	
clean: rm *.o Myshell
