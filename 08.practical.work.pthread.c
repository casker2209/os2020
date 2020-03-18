#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *func1(void *param){
	for(int i = 2;i <=1000000;i++)
	{	int b = 0;
		for(int a = 2;a<=i;a++)
		{
		if(i%a==0) b++;
		}
	if(b==1) printf("%d\n",i);
	}
	return NULL;
}

void *func2(void *param){
	int f1,f2,f;
	f1 = 1;
	f2 = 1;
	f = 2;
	while(f<=1000000)
	{
	printf("%d\n",f);
	f1 = f2;
	f2 = f;
	f = f1 + f2;
	}	
	return NULL;
}
int main() {
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,func1,NULL);	
	pthread_create(&tid2,NULL,func2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
