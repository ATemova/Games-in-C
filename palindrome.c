#include <stdio.h>
#include <string.h>

int main() {
    char str[100], reversed[100];
    int length, i, j;

    printf("Enter a string: ");
    gets(str);

    length = strlen(str);
    j = length - 1;

    for (i = 0; i < length; i++) {
        reversed[i] = str[j];
        j--;
    }
    reversed[i] = '\0';

    if (strcmp(str, reversed) == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
