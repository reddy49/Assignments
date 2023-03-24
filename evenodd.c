#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void* Even(int* temp);
void* Odd(int* temp);
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int main()
{
	int temp;
	int i;
	int res;
	pthread_t even;
	pthread_t odd;
	for(i = 0;i < 10;i++) {
		temp = rand();
		res = pthread_create(&even, NULL, (void*)Even, &temp);
		res = pthread_create(&odd, NULL, (void*)Odd, &temp);
		pthread_join(even, NULL);
		pthread_join(odd,NULL);
	}
	
}
void* Even(int* temp)
{
	pthread_mutex_lock(&lock);
	if(*temp%2 == 0) {
		printf("num is even%d\n",*temp);
	}
	//pthread_exit(0);
	pthread_mutex_unlock(&lock);
}
void* Odd(int* temp)
{
	pthread_mutex_lock(&lock);
	if(*temp%2 == 1) {
		printf("num is odd%d\n",*temp);
	}
	pthread_mutex_unlock(&lock);
}
