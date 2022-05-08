// ZJ a040 : Armstrong Number 阿姆斯壯數

#include <stdio.h>
#include <math.h>

int main(void) {

    int min, max, counter = 0;
    scanf("%d %d", &min, &max);

    for(int i = min; i < max; i++) {

#pragma region "#數位計算器()"
        int tmp = i, digits = 0; // i = input
        while(tmp/10 != 0) {
            tmp /= 10;
            digits++;
        }
        digits++;
        //printf("%d\n", digits); // debug
#pragma endregion

        tmp = i;
        int total = 0;
        for (int j = 0; j < digits; j++) {
            int digit = tmp % 10;
            //printf("%d\n", digit); // debug

            total += pow(digit, digits);
            tmp /= 10;
        }
        
        if(i == total) {
            printf("%d ", total);
            counter++;
        }

    }

    if(counter == 0) {
        printf("none");
    }

    return 0;
}

//AC (26ms, 152KB))
