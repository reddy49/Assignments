#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void* fun();
int main()
{
	int i = 0;
	pthread_t id;
	int res;
	int ret;
	res = pthread_create(&id, NULL,&fun, NULL);
		if(res != 0) {
		printf("thread is created");
		exit(0);
	}
	while(i<5) {
		printf("i am sumanth\n");
//		ret = pthread_detach(id);
		i++;
	}
//	pthread_join(id , NULL);
	//pthread_exit(0);
//	int ret;
	ret = pthread_detach(id);
	printf("detach = %d\n",ret);
	if(pthread_detach == 0) {
		printf("Succesful");
	}
}

void* fun()
{
	int i = 0;
	while(i < 5) {
		printf("i am reddy\n");
		i++;
	}
	pthread_exit(0);
}

