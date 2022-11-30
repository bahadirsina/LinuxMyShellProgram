all: Myshell writef execx

Myshell: Myshell.c
	gcc Myshell.c -o myshell
writef: writef.c
	gcc writef.c -o writef
execx: execx.c
	gcc execx.c -o execx
	
clean: rm *.o all
