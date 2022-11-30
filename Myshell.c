#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[],char ** envp) {
	time_t times = time(NULL);
	printf("TIME : %s",ctime(&times)); // The system takes the time and is printed on the screen.
	int w;
	int x;
	char arr [100];
	memset(arr, 0, 100); //This function resets the garbage values in the array.
	int frk1;
	printf("------- BAHADIR SINA'S MYSHELL -------\n");
	printf("cat   -> This command writes what you want to type on the screen.\n");
	printf("exit  -> This command allows you to exit the shell at any time.\n");
	printf("clear -> This command clears the shell screen.\n");
	printf("ls    -> This command will list you the files inside the folder.\n");
	printf("bash  -> This command allows entering bash in the system.\n");
	printf("comnd -> This command allows you to relist commands.\n");
	while(true){
		printf("myshell>> ");
		fgets(arr,100,stdin);  // The user is prompted for arguments.
      		int z = 0;
     		char tmp[10][10]; //A temporary matrix array is created.
     		int i,j,count;
    		j=0; count=0;
    		for(i=0; i <= (strlen(arr)); i++) {  //All entries entered by the user after myshell 
        		if(arr[i] == ' '|| arr[i] == '\0'){ //are separated by spaces and stored in a temporary array.
            			tmp[count][j]='\0';
            			count++;  
            			j=0;  
        		}else{
            			tmp[count][j]=arr[i];
            			j++;
        		}
        	}

        char *cp = tmp[0]; // Values were stored for comparison.
        char *cp0 = tmp[1];
        char *cpp = tmp[3];
        char *cpp0 = tmp[4];
	char *cp1 = "exit";
	char *cp2 = "cat";
	char *cp3 = "clear";
	char *cp4 = "ls";
	char *cp5 = "bash";
	char *cp6 = "comnd";
	char *cp7 = "exit\n";
	char *cp8 = "cat\n";
	char *cp9 = "clear\n";
	char *cp10 = "ls\n";
	char *cp11 = "bash\n";
	char *cp12 = "comnd\n";
	char *cp13 = "writef";
	char *cp14 = "-f";
	char *cp15 = "execx";
	char *cp16 = "-t";
	
	
	if (strcmp(arr, cp7) == 0){ //exit from the shell
		times = time(NULL);
		printf("TIME : %s",ctime(&times));
		printf("Successfully exited the Myshell...\n");
		break;
	} else if ((strcmp(arr, cp8) && strcmp(cp, cp2)) == 0){  //The cat argument worked and was printed to the screen.
		printf("cat: ");
		for(i=1;i < count;i++){
			printf("%s ",tmp[i]);
		}
	} else if (strcmp(arr, cp9) == 0){ //The screen is cleared thanks to this code block.
		system("clear");
	} else if (strcmp(arr, cp10) == 0){ // Listed the files inside the folder on the screen.
		system("ls -ltr");
	} else if (strcmp(arr, cp11)  == 0){ // It goes into bin/bash and runs whatever system bash is running.
		frk1 = fork();
		if(frk1 == 0){  // We can exit bash with exit thanks to fork.
			execve("/bin/bash",NULL,NULL);
		}else{
		wait(NULL);
		}
	} else if (strcmp(arr, cp12)  == 0){ // Writes the arguments that the user can use to the screen.
		printf("cat   -> This command writes what you want to type on the screen.\n");
		printf("exit  -> This command allows you to exit the shell at any time.\n");
		printf("clear -> This command clears the shell screen.\n");
		printf("ls    -> This command will list you the files inside the folder.\n");
		printf("bash  -> This command allows entering bash in the system.\n");
		printf("comnd -> This command allows you to relist commands.\n");
	
	} else if (strcmp(cp, cp13)  == 0 && strcmp(cp0, cp14)  == 0 ){ // Check "writef -f " 
		char *newargv[2];
		newargv[0] = tmp[2]; // Store the filename.
		newargv[1] = NULL;
		frk1 = fork(); // Thanks to these codes, by creating a fork, the child process is entered 
		if(frk1 == 0){
			x = execve("writef",newargv,envp); //into the "writef" file with the help of execv.
		}else{
			wait(&x);
		}
	}  else if (strcmp(cp, cp15)  == 0 && strcmp(cp0, cp16)  == 0 ){ // Check "execx -t" 	
		if(isdigit(tmp[2][0])){ // The number after "-t" is checked whether it is or not.
			char *newargv[4];
			newargv[0] = tmp[2]; // number of work
			newargv[1] = tmp[3]; // program name = writef
			newargv[2] = tmp[4]; // program shortname = -f
			newargv[3] = tmp[5]; // filename
			int number = atoi(tmp[2]);
			frk1 = fork();   // Thanks to these codes, by creating a fork, the child process is entered 
			if(frk1 == 0){
				w = execve("execx",newargv,envp); //into the "execx" file with the help of execv.
			}else{
				wait(&w);
			}
		} else{
			printf("Wrong command entered! Enter the correct command.\n");// When wrong argument is entered, a warning message is 
		}
	}
	else {
		printf("Wrong command entered! Enter the correct command.\n"); //given to the screen. Myshell continues to run.
		printf("If you want to relearn commands, use 'comnd'.\n");
	}
}
    return 0;
}



