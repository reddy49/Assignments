#include <stdio.h>
#include <stdlib.h>

int top1=-1;
int top2=-1;
int top3=-1;
int sta1[10]; //src
int sta2[10]; //des
int sta3[10]; //temp

void towerOfHanoi(int n) {
    int i, j, k,l,m;
    for (i = n;i>0;i--) {
        top1++;
        sta1[top1] = i;
    }
    //    for(i = top1;i>=0;i--) {
     //     printf("%d ",sta1[i]);
    //    }
    printf("\n");
    for(k = top1,l = top3, m = top2; k>=0||l>=0||m>=0;k--,l--,m--) {
        printf("%d |%d |%d\n", sta1[k],sta3[l],sta2[m]);
    }
    printf("\n");
    for(i = 1; i < (1 << n); i++) {
        j = (i & (i-1)) % 3;
        k = ((i | (i-1)) + 1) % 3;
        if( j == 0 && k == 1) {
            top2++;
            sta2[top2] = sta1[top1];
            top1--;
        } else if(j == 0 && k == 2 ) {
            top3++;
            sta3[top3] = sta1[top1];
            top1--;
        } else if(j == 1 && k == 0) {
            top1++;
            sta1[top1] = sta2[top2];
            top2--;
        } else if(j == 1 && k == 2) {
            top3++;
            sta3[top3] = sta2[top2];
            top2--;
        } else if(j == 2 && k == 0) {
            top1++;
            sta1[top1] = sta3[top3];
            top3--;
        } else if (j == 2 && k == 1){
            top2++;
            sta2[top2] = sta3[top3];
            top3--;
        }
        printf("s |t |d |\n");
        for(k = top1,l = top2, m = top3; k>=0||l>=0||m>=0;k--,l--,m--) {
                printf("%d |%d |%d\n", sta1[k],sta2[l],sta3[m]);
       }
       printf("\n");
    }
      //  printf("Move disk  from peg %d to peg %d\n", /*__builtin_ctz(i ^ (i-1)),*/ j, k);
}

int main() {
    int n; // number of disks
	printf("Enter no of discs");
	scanf("%d", &n);
    towerOfHanoi(n);
    return 0;
}
