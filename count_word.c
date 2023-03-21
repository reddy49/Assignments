#include <stdio.h>
int main()
{
	FILE *fp = fopen("file1.txt", "r");
    int count = 0;
    int word = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\n') {
        	word = 0;
            } else {
                if (!word){
                	count++;
                	word = 1;
                }
        	}
    }
    printf("%d", count);
    fclose(fp);
    return 0;
}
