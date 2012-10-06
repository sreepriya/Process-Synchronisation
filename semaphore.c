#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
#define MAX 10000
int count = 0;
sem_t mutex;

int main(){
    void *add(void* ptr);
    sem_init(&mutex,0,1);
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,add,(void*)1);
    pthread_create(&thread2,NULL,add,(void*)2);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    if(count != 2*MAX){
        printf("\n BOOM!! Count is : %d",count);
    }
    else 
        printf("\n Correct!! count is : %d",count);
    sem_destroy(&mutex);
    return 0;

}
void* add(void *ptr){
    int i,tmp;
    int tnum=(int)ptr;
    for(i=0; i < MAX ;i++){
        sem_wait(&mutex);
        count++;
        sem_post(&mutex);
    }

}
