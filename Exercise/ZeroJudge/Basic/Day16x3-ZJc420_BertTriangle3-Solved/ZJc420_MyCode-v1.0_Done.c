// ZJ c420 : Bert's Triangle 3

#include <stdio.h>

int main(void) {
    
    int level = 0;
    scanf("%d", &level);

    for (int i = 0, odd = 0; i < level; i++, odd+=2) {
        
        for (int j = 1; j < (level-i); j++) {
            printf("_");
        }

        for (int j = 0; j <= odd; j++) {
            printf("*");
        }

        for (int j = 1; j < (level-i); j++) {
            printf("_");
        }
        
        printf("\n");
    }

    return 0;
}



//AC (2ms, 104KB)
