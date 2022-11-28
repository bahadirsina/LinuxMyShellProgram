#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char arr [100];
	memset(arr, 0, 100);
	printf("------- BahadirSina's Myshell -------\n");
	printf("cat   -> This command writes what you want to type on the screen.\n");
	printf("exit  -> This command allows you to exit the shell at any time.\n");
	printf("clear -> This command clears the shell screen.\n");
	printf("ls    -> This command will list you the files inside the folder.\n");
	printf("bash  -> This command allows entering bash in the system.\n");
	printf("comnd -> This command allows you to relist commands.\n");
	while(true){
	printf("myshell>> ");
	fgets(arr,100,stdin);

	char *cp1 = "exit\n";
	char *cp2 = "cat\n";
	char *cp3 = "clear\n";
	char *cp4 = "ls\n";
	char *cp5 = "bash\n";
	char *cp6 = "comnd\n";
	
	if (strcmp(arr, cp1) == 0){ //exit from the shell
	break;
	} else if (strcmp(arr, cp2) == 0){ 
	printf("cat");
	} else if (strcmp(arr, cp3) == 0){
	system("clear");
	} else if (strcmp(arr, cp4) == 0){
	system("ls -ltr");
	} else if (strcmp(arr, cp5) == 0){
	system("bash");
	} else if (strcmp(arr, cp6) == 0){
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
