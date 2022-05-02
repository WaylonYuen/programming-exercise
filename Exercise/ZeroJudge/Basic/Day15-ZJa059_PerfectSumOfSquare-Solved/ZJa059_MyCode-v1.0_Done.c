// ZJ a059 : Perfect sum of square 完全平方和

#include <stdio.h>
#include <math.h>

int main(void) {
    
    int counter = 0;
    scanf("%d", &counter);

    for (int i = 0; i < counter; i++) {
        
        int min, max, sum = 0;
        scanf("%d", &min);
        scanf("%d", &max);

        for (int j = min; j < max; j++) {

            //關鍵：取根後強制轉型為整數，再開平方如果無法還原數值則表示有餘數
            int a = sqrt(j);
            if((a*a) == j) {
                sum += j;
            }

        }

        printf("Case %d: %d\n", i + 1, sum);
    }

    return 0;
}

//AC (1ms, 124KB)
