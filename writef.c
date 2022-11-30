#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[],char ** envp) {
	printf("Writef opened...\n");
	FILE *fp;
	char* fName = argv[0];   // Here stored the filename argument sent from myshell.
  	if ((fp = fopen(fName, "a+"))) {   // File is opened and check if there is a file with "a+". 
  		time_t times = time(NULL);  //If it exists in the system, it is overwritten, if not, it is created.
  		fprintf(fp,"TIME : %s",ctime(&times));  // The system time is printed on the screen.
  		fprintf(fp," pid= %d ppid= %d\n",getpid(),getppid()); // Parent id and normal id are printed on the screen.
  		fclose(fp);  // File is closed.
  	} else{
      		printf("Error: File is not open!\n");
      		exit(1);
  	}
    return 0;
}

