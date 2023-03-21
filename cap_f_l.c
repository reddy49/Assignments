#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *ch;
	FILE *fp;
	ch = (char *) malloc (50 * sizeof(char));
	fp = fopen("Capitalize.txt", "r+");
//	printf("Enter text");
//	fgets(ch,50,stdin);
//	fprintf(fp, "%s", ch);

	fseek(fp, 0 ,SEEK_SET);
	int i;
	int word = 0;
//	while ((ch[i] = fgets(fp)) != EOF) {
//	while ((ch[i] = fgetc(fp))	!= EOF) {
	fgets(ch, 50, fp);
	ch[0] = ch[0] - 32;
	for (i = 0; ch[i] != EOF; i++) {
//		ch[1] = ch[1] - 32;
		if(ch[i] == ' ') {
//			word = word + 1;	
			ch[i + 1] = ch[i + 1] - 32;
		}
//		i++;
	}
	fseek(fp,0,SEEK_SET);
	fputs(ch, fp);
	fprintf(fp, "%s", ch);
//	printf("%d", word);
	fgets(ch, 50, fp);
	printf("%s", ch);
	fclose(fp);
}
