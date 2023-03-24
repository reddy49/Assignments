#include <stdio.h>
#include<pthread.h>
int i = 2;
void* foo(void *p) 
{
    int i = 1;
    printf("recievd value = %d\n",*(int *)p);
    pthread_exit(&i);
}
int main(void)
{
    pthread_t id;
    int j = 1;
    pthread_create(&id,NULL,foo,&j);
    int *ptr;
    pthread_join(id,(void**)&ptr);
    printf("value recievd=%d",*ptr);

    return 0;
}
