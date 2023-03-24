#include<stdio.h>
#include<string.h>

//char *pri(char *str,char *str1);
int main() {
	char ch[25][25] = {{"a b c d"}, 
					   {"e f g h"},
					   {"i j k l"},
					   {"m n o p"},
					   {"q r s t"}, 
					   {"u v w x"}, 
					   {"y z"}};
	char str[25][25],s1[25][25],s2[25][25];
	int n,i,j,k;
	char a[10],b[10],c[10],d[10];
	char a1[17],b1[17],c1[17],d1[17];
	for(i = 0;i<7;i++) {
		strcpy(str[i],ch[i]);
		printf("%d. %s\n",i,ch[i]);
	}
	j = 0;
	for(i = 0;i<7;i++) {
		printf("Enter line: and -1 for stop\n");
		scanf("%d", &n);
		k = i;
		while(k<7) {
			if(k == n || n>=0) {
				strcpy(s1[j],str[n]);
				printf("s1=%s\n",s1[j]);
				j++;
				i = 0;
				break;
			}
			k++;
		}
		if(n < 0) 
			break;
		else 
			continue;
	}
	for(i = 0;i<j;i++) {
//		printf("s1[%d] = %s\n",i,s1[i]);
	}
	i = 0;
	int f=0,g=0,h=0;
	for(k = 0; k<j ; k++) {
//		if(k<j) {
			strcpy(a,s1[k]);
//			printf("%s\n",a);
			a1[i++] = a[0];
			a1[i++] = ' ';
			b1[f++] = a[2];
			b1[f++] = ' ';
			c1[g++] = a[4];
			c1[g++] = ' ';	
			d1[h++] = a[6];
			d1[h++] = ' ';
//		}
	}
	a1[i] = '\0';
	b1[i] = '\0';
	c1[i] = '\0';
	d1[i] = '\0';
	printf("0.  %s\n1.  %s\n2.  %s\n3.  %s\n", a1,b1,c1,d1);
	char q[25][25];
	char p[25][25];
	i = 0;
//	while(i < 4) {
	strcpy(q[0],a1);
	strcpy(q[1],b1);
	strcpy(q[2],c1);
	strcpy(q[3],d1);
	int jj = 0;
	for(i = 0;i<4;i++) {
		printf("Enter line: and -1 for stop");
		scanf("%d", &n);
		k = i;
		while(k<4) {
			if(k == n || n>=0) {
				strcpy(p[jj],q[n]);
				printf("s1=%s\n",p[jj]);
				jj++;
				i = 0;
				break;
			}
			k++;
		}
		if(n < 0) 
			break;
		else 
			continue;
	}
	char ddd[20],dd[20];
	for(i = 0,n=0;i<j || n < jj;i++,n++) {
		//	printf("\n%s   ==   %s", s1[i],p[n]);
		strcpy(ddd,s1[i]);
		strcpy(dd,p[n]);
		int g=0,h=0;
//		int flag = 0;
    	while(ddd[g]) {
        	h = 0;
        	while(dd[h]) {
            	if(ddd[g] == dd[h]) {
                	printf("%c",ddd[g]);
//					flag = 1;
					break;
            	}
            	h++;
        	}
//			if(flag == 1)
//				break;
        	g++;
    	}
	}
/*	i = 0;
	int x,y;
	while(i<j) {
		strcpy(a,s1[k]); 
		for (x = 0;x<4;x++) {
			for(y = 0;y<4;y++) {
				if(a1[x] == a[y]) {
	//				printf("%c",a1[x]);
				} else if (b1[x] == a[y]) {
	//				printf("%c",b1[x]);
				} else if (c1[x] == a[y]) {
	//				printf("%c", c1[x]);
				} else if(d1[x] == a[y]) {
	//				printf("%c", d1[x]);
				}
			}
		}
		i++;
		k++;
	}*/
	/*	if(j >= 1)
			if(k == 1) {
				strcpy(b,s1[k]);
				a1[i] = a[i];
				b1[i] = b[i + 1];
				c1[i] = c[i + 2];
				d1[i] = d[i + 3];

			strcpy(c,s1[i]);
				a1[i] = a[i];
				b1[i] = b[i + 1];
				c1[i] = c[i + 2];
				d1[i] = d[i + 3];

			strcpy(d,s1[i]);
				a1[i] = a[i];
				b1[i] = b[i + 1];
				c1[i] = c[i + 2];
				d1[i] = d[i + 3];*/
}	





