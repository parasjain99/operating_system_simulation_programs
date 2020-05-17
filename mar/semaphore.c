#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

sem_t s;

void *thread(void *arg){
    static int i=0;
    sem_wait(&s);
    printf("hello %d",i);
    i++;
    sleep(2);
    sem_post(&s);
}

int main(){
    sem_init(&s,0,1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,thread,NULL);
    sleep(2);
    pthread_create(&t2,NULL,thread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&s);
    return 0;

}

// max element in a large array using semaphore pthreads

// g++ -pthread sema.c
// ./a.out