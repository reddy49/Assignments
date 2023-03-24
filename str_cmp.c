#include <stdio.h>
#include<string.h>
#include<ctype.h>
int strc(const char *ch,const char *ch1,int len);
int main()
{
   const char *ch = "sumanth";
   const char *ch1 = "sumnn";
   int len = 5;
   int n = strc(ch,ch1,len);
   printf("%d\n",n);
    if(n == 0) {
       printf("strings are same");
   } else if(n > 0){
       printf("s1 is greater than s2");
   } else {
       printf("s2 is greater than s1");
   }
}
int strc(const char *ch,const char *ch1,int len) {
    unsigned char c1,c2;
   do {
       c1 = *ch++;
       c2 = *ch1++;
      if(!c1 || !c2) {
          break;
      }
      if (c1 == c2) {
          continue;
      }
      c1 = tolower(c1);
      c2 = tolower(c2);
      if(c1 != c2) {
          break;
      }
   } while(*ch && *ch1);
   return (int)c1 - (int)c2;
}

