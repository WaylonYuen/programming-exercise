// ZJ a022 : Palindrome 迴文

#include <stdio.h>

#define SIZE 1000 // Given

int main(void) {

    char str[SIZE] = {};
    scanf("%s", str);

    int len = 0;
    while (len < SIZE) {
        if(str[len] == '\0') break;
        len++;
    }

    for (int i = 0, j = len-1; i < len/2; i++, j--) {
        if(str[i] != str[j]) {
            printf("no");
            return 0;
        }
    }

    printf("yes");
    return 0;
}

//AC (2ms, 96KB))
