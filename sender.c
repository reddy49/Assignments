#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<mqueue.h>
#define SIZE 50

/*struct mq_attr {
	long mq_flags;
	long mq_maxmsg;
	long mq_msgsize;
	long mq_curmsgs;
	};*/
int main()
{
	int mqd_t;
	int mq_create, mq_snd_open,mq_rec_open;
	char buff[SIZE];
	int mq_ret,i,ret_rec;
	int len;
/*	struct mq_attr msg;
	msg.mq_flags = 0;
	msg.mq_maxmsg = 2;
	msg.mq_msgsize = 20;
	msg.mq_curmsgs = 0;
	mq_create = mq_open ("/mymq", O_CREAT | O_RDWR, 0744, &msg);
	if (mq_create == 3) {
		printf("msg q is created\n");
	} else {
		printf("msg q is not created\n");
	}*/
	mq_snd_open = mq_open("/mymq",O_WRONLY);
	printf("Enter msg\n");
	fgets(buff, SIZE,stdin);
	len = strlen(buff);
	mq_ret = mq_send(mq_snd_open,buff,len + 1,0);
	if(mq_ret == 0) {
		printf("sent succesful\n");
	} else {
		printf("Sent unseccesful\n");
	} /*
	mq_rec_open = mq_open("/mymq",O_RDONLY);
	ret_rec = mq_receive(mq_rec_open, buff, sizeof(buff), NULL);
	printf("Message : %s\n", buff);*/
}

