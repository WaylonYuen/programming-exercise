// ZJ c418 : Bert's Triangle 1

#include <stdio.h>

int main(void) {
    
    int level = 0;
    scanf("%d", &level);
    for (int i = 0; i <= level; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}


//AC (2ms, 92KB)
