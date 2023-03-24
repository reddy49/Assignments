/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    char ch[100] = "sumanthreddy";
    char str[100] = "reddy";
 //   char res[20];
    int i,j,k,len = 0;
    for(k = 0; str[k] != '\0';k++) {
        len++;
    }
      printf("%d",len);
    for(i = 0; ch[i] != '\0';i++) {
        for (j = 0;str[j] != '\0'; ) {
            if (ch[i] == str[j]) {
            j++;
        }
        else 
        j=0;
    }
    }
  
    if (j == len) {
     printf("1");
    }
    else 
    printf("0");
    return 0;
}

