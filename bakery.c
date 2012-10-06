#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
struct thread_data{
    int thread_id;
    char *message;
};
bool Entering[5]={false};
int Number[5]={0};
lock(int i){
    Entering[i]=true;
    Number[i]=1+max(Number[1])
}
struct thread_data thread_data_array[10];
int main(){
    void *print_message(void *ptr);
    char *mssg1="Thread_1",*mssg2 = "Thread_2";
    int iret1,iret2;
    pthread_t thread1,thread2;
    int *thread1_ret_value,*thread2_ret_value;
    iret1=pthread_create(&thread1,NULL,print_message,(void*)mssg1);
    iret2=pthread_create(&thread2,NULL,print_message,(void*)mssg2);
    pthread_join(thread1,(void**)&thread1_ret_value);
    pthread_join(thread2,(void**)&thread2_ret_value);
    printf("iret1: %d\n",iret1);
    printf("iret2 %d\n",iret2);
    printf("From T1: %d\n",*thread1_ret_value);
    printf("From T2: %d\n",*thread2_ret_value);
    int k=pthread_self();
    printf("Id: %d\n",k);
    exit(0);
    return EXIT_SUCCESS;
}
void* print_message(void*ptr)
{
    char *message = (char*)ptr;
    int exit_val=2;
    printf("%s\n",message);
    pthread_exit(&exit_val);

}
