// ZJ f063 : The Strongest Chain 最強鏈條

#include <stdio.h>

int main(void) {

    int chainNum = 0, strongest;
    scanf("%d", &chainNum);
    for (int i = 0; i < chainNum; i++) {

        int chainLen = 0, weakest, chain;
        scanf("%d", &chainLen);
        for (int j = 0; j < chainLen; j++) {
            scanf("%d", &chain);
            if(chain <= weakest || j == 0) {
                weakest = chain;
            }
        }

        if(strongest < weakest || i == 0) {
            strongest = weakest;
        }

    }

    printf("%d", strongest);

    return 0;
}

//AC (3ms, 104KB))
