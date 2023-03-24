#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>
#include <sys/ipc.h>

 

#define SIZE 500

 

int main()
{
    struct mq_attr attr;
    mqd_t mq_des;
    FILE *fp;
    char buf[SIZE];

    mq_des = mq_open("/queue", O_RDONLY, 0666, NULL);
	
    printf("mq_des: %d\n", mq_des);
    fp = fopen("output.txt", "a+");
    mq_receive(mq_des, buf, SIZE, 0);
    printf("%s\n", buf);
    fprintf(fp,"%s", buf);
    mq_close(mq_des);
    fclose(fp);
}
