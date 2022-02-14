#include <stdio.h>

int main(void) {

    int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char month_Eng[12][20] = {
         "Sunday", "Monday", "Tuesday", "Thursday", "Thursday", "Firday", "Saturday"
    };

    int dataSize = 0;
    scanf("%d", &dataSize);
    for (int i = 0; i < dataSize; i++) {
        int mm = 0, dd = 0;
        scanf("%d %d", &mm, &dd);

        int total_days = month[--mm] - dd;
        //printf("day: %d\n", total_days);
        for (int j = mm + 1; j < 12; j++) {
            total_days += month[j];
            //printf("[%d] %d\n", j + 1, month[j]);
        }
        
        int ans = 6 - (total_days % 7);
        printf("ans: %s\n", month_Eng[ans]);
    }

    return 0;
}
