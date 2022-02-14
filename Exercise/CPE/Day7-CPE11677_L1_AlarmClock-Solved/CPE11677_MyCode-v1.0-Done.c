// 2019/12/17 CPE
// Start Time: 14.05.03

#include <stdio.h>
#include <stdlib.h>

void Result(int h, int m) {
    printf("\t\t\t\t\t%d:%d = %d\n", h, m, h * 60 + m);
}

int main(void) {

    int h = 0, h1 = -1, h2 = -1;
    int m = 0, m1 = -1, m2 = -1;

    while (scanf("%d %d %d %d", &h1, &m1, &h2, &m2)) {
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;
        //printf("Debug => %d:%d to %d:%d\n", h1, m1, h2, m2);

        //15:30~15:52

        //一般小時
        if(h1 < h2) {
            h = h2 - h1;
            //一般分鐘
            if(m1 <= m2) {
                printf("\t\t\tCase 1: normal case\n");
                m = m2 - m1;

            //分鐘反追
            } else {
                printf("\t\t\tCase 2: \n");
                h--;
                m = (60 - m1) + m2;
            }

        //同一小時
        } else if(h1 == h2) {
            h = 0;

            //一般分鐘
            if(m1 <= m2) {
                printf("\t\t\tCase 3\n");
                m = m2 - m1;
            
            //分鐘反追 -> 與跨日相同
            } else {
                printf("\t\t\tCase 4\n");
                h = 23;
                m = (60 - m1) + m2;
            }

        //跨日
        } else if(h1 > h2) {
            printf("\t\t\tCase 5: to next day\n");
            h = 24 - (h1 - h2);
            h--;
            m = (60 - m1) + m2;
        }


        Result(h, m);
    }

    printf("End of run...\n");

    return 0;
}