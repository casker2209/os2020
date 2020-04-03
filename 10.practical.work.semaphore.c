#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_mutex_t mutex;



void *func1(void *param){
	for(int i = 2;i <=100;i++)
	{	
    pthread_mutex_lock(&mutex);
        printf("Mutex func1 locked\n");
        int b = 0;
		for(int a = 2;a<=i;a++)
		{
		if(i%a==0) b++;
		}
	if(b==1) printf("%d\n",i);
    printf("mutex func1 unlocked\n");
    pthread_mutex_unlock(&mutex);
	}
	return NULL;
}
void *func2(void *param){
	int f1,f2,f;
	f1 = 1;
	f2 = 1;
	f = 2;
	while(f<=100)
	{
    pthread_mutex_lock(&mutex);
    printf("Mutex func2 locked\n");
	printf("%d\n",f);
	f1 = f2;
	f2 = f;
	f = f1 + f2;
    printf("Mutex func2 unlocked\n");
    pthread_mutex_unlock(&mutex);
	}	
	return NULL;
}

int main() {
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,func1,NULL);	
	pthread_create(&tid2,NULL,func2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
    pthread_mutex_destroy(&mutex);
   
	return 0;
}
