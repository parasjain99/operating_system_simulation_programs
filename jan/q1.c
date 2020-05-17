#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	if(fork()==0)
		printf("Hello inside child\n");
	else
		printf("Hello inside parent\n");
	return 0;
}
