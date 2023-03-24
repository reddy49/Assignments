#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>

#define SIZE 500

 

int main()
{
    mqd_t mq_des;
    int send;
    FILE *fp;
    char buf[SIZE];
    char buf2[SIZE];
    char buf3[SIZE];
    int count;
    int part;
    int index = 0;
    char ch;
    int i = 0;
    int j = 0;
    int k = 0;
    struct mq_attr attr = {
    .mq_flags = 0,
    .mq_maxmsg = 10,
    .mq_msgsize = SIZE,
    .mq_curmsgs = 0
    };

    mq_des = mq_open("/queue", O_CREAT | O_WRONLY, 0666, &attr);
	if (mq_des == -1) {
        printf("Message not created\n");
        exit(0);
    }
        //open file
    fp = fopen("input.txt", "r");
        //count char
    fseek(fp, 0, SEEK_END);
    count = ftell(fp);
    printf("%d\n", count);
    count = count / 3;
    printf("%d\n", count);
    fseek(fp, 0, SEEK_SET);
    while ((ch = fgetc(fp)) != EOF)  {
          if (index < count) {
              buf[i] = ch;
              i++;
          } else if (index >= count && index < 2 * count) {
    	        buf2[j] = ch;
                j++;
        	   } else {
                   buf3[k] = ch;
                   k++;
                }
                index++;
        	}
	printf("%s\n", buf);
    printf("%s\n", buf2);
    printf("%s\n", buf3);
    //send queue
    send = mq_send(mq_des, buf, SIZE, 2);
    mq_send(mq_des, buf2, SIZE, 1);
    mq_send(mq_des, buf3, SIZE, 0);

    if (send == -1) {
        printf("MSG not sent\n");
        exit(1);
    }
    mq_close(mq_des);
    fclose(fp);
}
