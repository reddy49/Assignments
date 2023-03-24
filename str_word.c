#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void remove_substring(char *str, char *sub) {
    int i, j, k;
    int sub_len = strlen(sub);
    for (i = 0; str[i] != '\0'; i++) {
        j = 0;
        k = i;
        while (str[k] == sub[j] && sub[j] != '\0') {
            k++;
            j++;
        }
        if (sub[j] == '\0') {
            while (str[k] != '\0') {
                str[i++] = str[k++];
            }
            str[i] = '\0';
            break;
        }
    }
}

int main() {
    char *str = (char *) malloc (30 * sizeof(char));
    char *sub = (char *) malloc (20 * sizeof(char));
	printf("Enter string:");
	fgets(str,30,stdin);
	printf("Enetr substring:");
	fgets(sub,20,stdin);
	*(str + strlen(str) - 1) = '\0';
	*(sub + strlen(sub) - 1) = '\0';
    printf("Original string: %s\n", str);
    remove_substring(str, sub);
    printf("After removing the substring: %s\n", str);

    return 0;
}

