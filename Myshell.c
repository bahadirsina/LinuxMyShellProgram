#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[]) {
	time_t times = time(NULL);
	printf("TIME : %s",ctime(&times));
	int i;
	char arr [100];
	memset(arr, 0, 100);
	printf("------- BAHADIR SINA'S MYSHELL -------\n");
	printf("cat   -> This command writes what you want to type on the screen.\n");
	printf("exit  -> This command allows you to exit the shell at any time.\n");
	printf("clear -> This command clears the shell screen.\n");
	printf("ls    -> This command will list you the files inside the folder.\n");
	printf("bash  -> This command allows entering bash in the system.\n");
	printf("comnd -> This command allows you to relist commands.\n");
	while(true){
		printf("myshell>> ");
		fgets(arr,100,stdin);
      		int z = 0;
     		char tmp[10][10];
     		int i,j,count;
    		j=0; count=0;
    		for(i=0; i <= (strlen(arr)); i++) {
        		if(arr[i] == ' '|| arr[i] == '\0'){
            			tmp[count][j]='\0';
            			count++;  
            			j=0;  
        		}else{
            			tmp[count][j]=arr[i];
            			j++;
        		}
        	}

        char *cp = tmp[0];
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
	
	if (strcmp(arr, cp7) == 0){ //exit from the shell
		times = time(NULL);
		printf("TIME : %s",ctime(&times));
		printf("Successfully exited the Myshell...\n");
		break;
	} else if ((strcmp(arr, cp8) && strcmp(cp, cp2)) == 0){ 
		printf("cat: ");
		for(i=1;i < count;i++){
			printf("%s ",tmp[i]);
		}
	} else if (strcmp(arr, cp9) == 0){
		system("clear");
	} else if (strcmp(arr, cp10) == 0){
		system("ls -ltr");
	} else if (strcmp(arr, cp11)  == 0){
		int frk1 = fork();
		if(frk1 == 0){
			i = execve("/bin/bash",NULL,NULL);
		}else{
		wait(&i);
		}
	} else if (strcmp(arr, cp12)  == 0){
		printf("cat   -> This command writes what you want to type on the screen.\n");
		printf("exit  -> This command allows you to exit the shell at any time.\n");
		printf("clear -> This command clears the shell screen.\n");
		printf("ls    -> This command will list you the files inside the folder.\n");
		printf("bash  -> This command allows entering bash in the system.\n");
		printf("comnd -> This command allows you to relist commands.\n");
	
	} else {
		printf("Wrong command entered! Enter the correct command.\n");
		printf("If you want to relearn commands, use 'comnd'.\n");
	}
}
    return 0;
}


