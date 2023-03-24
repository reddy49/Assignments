#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cricket(int);
int cricket1(int,int);
int main()
{
	int p1,p2;
	int ran,s,over;
	printf("Enter overs\n");
	scanf("%d", &over);
	srand(time(0));
	printf("Toss\n");
	scanf("%d", &s);
	ran = (rand() % (2 - 1 + 1)) + 1;
	if(ran == 1) {
		printf("heads\n");
	} else {
		printf("tails\n");
	}
	printf("first innings is started\n");
	p1 = cricket(over);
	printf("first innings is completed%d\n",p1);
	printf("\n");
	printf("second innings is started\n");
	p2 = cricket1(over,p1);
	printf("Second innings is completed%d\n",p2);
	if(p1 < p2) {
		printf("player 2 wins\n");
	} else {
		printf("player 1 wins\n");
	}
}
int cricket(int over) {
	int n,bat[30];
	int r;
	int wic = 0;
	srand(time(0));
	int total = 0;
	int j = 1,i;
	char s1[20],s2[20];
//	printf("Enter player name\n");
//	fgets(s1,20,stdin);
//	printf("Enter player name\n");
//	fgets(s2,20,stdin);
	while(j <= over) {
		for (i = 1; i < 7;i++) {
			scanf("%d",&bat[i]);
			r = (rand() % (9  - 1 + 1)) + 1;
			if(r == 9 || r == 5) {
				wic++;
		//		printf("Player %s is out\n",s1);
				printf("%d over %d ball is wicket\n",j,i);
			}
			else if(r == 7) {
				printf("%d over %d ball is = wide\n",j,i);
				total = total + 1;
				i--;
			} 
			else if(r == 8) {
				printf("%d over %d ball is = No ball\n",j,i);
				i--;
				total = total + 1;
			}
			else {
				printf("%d over %d ball is =%d\n",j,i, r);
				total = total + r;
			}
		}
		printf("%d over is completed\n",j);
		i = 1;
		printf("after %d over runs is %d and wickets is %d\n",j,total,wic);
		j++;
		if(wic == 10) {
			return total;
		}
	}
	printf("total 1st innings is =%d\n",total);
	return total;
}
int cricket1(int over,int p1) {
	int n,bat[30];
	int r;
	int p2 = p1 + 1;
	int wic = 0;
	srand(time(0));
	int total = 0;
	int j = 1,i;
	int b = over * 6;
	while(j <= over) {
		for (i = 1; i < 7;i++) {
			scanf("%d",&bat[i]);
			r = (rand() % (9  - 1 + 1)) + 1;
			if(r == 5 || r== 9) {
				wic++;
				printf("%d over %d ball is wicket\n",j,i);
				b--;
			}else if(r == 7) {
				printf("%d over %d ball is = wide\n",j,i);
				total = total + 1;
				p2 = p2 -1;
				i--;
			} 
			else if(r == 8) {
				printf("%d over %d ball is = No ball\n",j,i);
				i--;
				total = total + 1;
				p2 = p2 -1;
			}
			else {
				printf("%d over %d ball is =%d\n",j,i, r);
				b--;
				total = total + r;
				p2 = p2 - r;
			}
		}
		printf("%d over is completed\n",j);
		i = 1;
		printf("after %d over runs is %d and wickets is %d\n",j,total,wic);
		printf("you need %d runs by %d balls\n",p2,b);
		if(p1 < total) {
			printf("total second innings is =%d\n",total);
			return total;
		}
		j++;
		if(wic == 10) {
			return total;
		}
	}
	printf("total second innings is =%d\n",total);
	return total;
}
