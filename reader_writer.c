/*-----------------------------------------------
  Reader Writer Problem with priority for READER
-------------------------------------------------*/

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<assert.h>

sem_t mutex,wrt;
int readcount;
int item ;

void *reader(void*id){
    int reader_id = (int)id;
    sem_wait(&mutex);
    readcount++;
    if(readcount == 1){
        sem_wait(&wrt);
    }
    sem_post(&mutex);
    int val;
    sem_getvalue(&mutex,&val);
    printf("[Reader : %d ]The value of shared item is : %d\n",reader_id,item);
    printf("Current mutex value is : %d\n",val);
    sem_wait(&mutex);
    readcount--;
    if(readcount == 0){
        sem_post(&wrt);
        printf("\nA writer may write now !! \n");
    }
    sem_post(&mutex);
}
void *writer(void *id){
    int writer_id = (int)id;
    sem_wait(&wrt);
    item = item+10;
    printf("[Writer %d ] The writer adds 10 to previous value of item : %d\n",writer_id,item);
    sem_post(&wrt);
}


int main(){
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    pthread_t t1,t2,t3,t4,t5;
    //Thread creation 
    assert(pthread_create(&t3,NULL,writer,(void*)1)==0);
    assert(pthread_create(&t2,NULL,reader,(void*)2)==0);
    assert(pthread_create(&t5,NULL,reader,(void*)3)==0);
    assert(pthread_create(&t1,NULL,reader,(void*)1)==0);
    assert(pthread_create(&t4,NULL,writer,(void*)2)==0);
    printf("2 Readers and 2 writers created...\n") ;
    pthread_exit(NULL);
    return 0;
}
