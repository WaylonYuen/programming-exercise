// ZJ c419 : Bert's Triangle 2

#include <stdio.h>

int main(void) {
    
    int level = 0;
    scanf("%d", &level);

    for (int i = 0; i < level; i++) {
        for (int j = 1; j < level - i; j++) {
            printf("_");
        }
        for (int k = 0; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}


//AC (2ms, 100KB)
