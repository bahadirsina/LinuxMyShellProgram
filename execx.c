#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[],char ** envp) {
	printf("Execx opened...\n");
	int s;
	char* wNum = argv[0]; // number of work
	char* pName = argv[1];// program name = writef
	char* sName = argv[2];// program shortname = -f
	char* fName = argv[3];// filename
	int wn = atoi(argv[0]); // Convert the number
	if(strcmp(pName, "writef")  == 0 && strcmp(sName, "-f")  == 0 ){ // Check the "writef -f"
		for(s = 0 ; s < wn ; s++){ // The for loop returns as many as the sent number.
			char *newargv[2];
			newargv[0] = argv[3];
			newargv[1] = NULL;
			execve("writef",newargv,envp); // Called the "writef" file with the help of execv.
		}
	} else {
		printf("Wrong command entered! Enter the correct command.\n");	
			 
	}
    return 0;
}

