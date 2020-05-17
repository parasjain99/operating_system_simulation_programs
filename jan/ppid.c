#include <stdio.h>
#include<sys/types.h> 
#include <unistd.h> 


int main() { 
	int x = fork(); 
	if (x == 0) {
		printf("inside child\n"); 
		printf("Parent Process id : %d\n", getppid()); 
		printf("Child Process id:%d\n ", getpid()); 
	}
	else {
		printf("inside parent\n"); 
		printf("Parent Process id : %d\n", getpid()); 

	} 
	return 0; 
} 

