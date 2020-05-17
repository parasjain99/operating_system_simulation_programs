#include<stdio.h> 
#include<sys/wait.h> 
#include<unistd.h> 

int main() { 
	int x = fork();
	
	if (x == 0){
		printf("inside child\n");
		printf("child terminated\n"); 
	}
		 
	else { 
		printf("inside parent \nwaiting for child to terminate\n");
		wait(NULL); 
		printf("wait over parent continues...\n");
		printf("parent terminated\n");
		
	}
	return 0; 
} 

