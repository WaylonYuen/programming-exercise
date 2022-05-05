// ZJ a020 : ID Test

#include <stdio.h>

int main(void) {

    int ref[] = {
        10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33
    };

    char idStr[10];
    int result = 0;

    scanf("%s", idStr);

    int engNum = ref[idStr[0]-65];

    result += (engNum - engNum%10)/10;
    result += (engNum%10) * 9;
    for (int i = 8, j = 1; i > 0; i--, j++) {
        result += ((idStr[j]-48) * i);
    }
    result += idStr[9]-48;

    if(result%10 == 0) {
        printf("real");
    }else{
        printf("fake");
    }

    return 0;
}

//AC (2ms, 96KB))
