#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fptr1;
    FILE *fptr2;
    char ch;
    fptr1 = fopen("file1.txt", "r");
    if (fptr1 == NULL) {
    	printf("Cannot open file \n");
             exit(0);
        }
    fptr2 = fopen("file2.txt", "w");
    if (fptr2 == NULL) {
         printf("Cannot open file\n");
         exit(0);
        }
    ch = fgetc(fptr1);
    while (ch != EOF) {
                fputc(ch,fptr2);
                ch = fgetc(fptr1);
        }
        printf("\nContents copied to file2.txt");
        fclose(fptr1);
        fclose(fptr2);
        return 0;
}
