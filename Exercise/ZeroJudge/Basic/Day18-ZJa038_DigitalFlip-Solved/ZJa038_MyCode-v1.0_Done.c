// ZJ a038 : Digital flip 數字翻轉

#include <stdio.h>

#define bool int
#define True 1
#define False 0

int main(void) {

    int data = 0;
    scanf("%d", &data);
    bool skip = True;

    while((data-10) > 0) {

        while(skip) {
            if(data%10 != 0) {
                skip = False;
            } else {
                data /= 10;
            }
        }

        printf("%d", data%10);
        data /= 10;
    }

    printf("%d", data);
    return 0;
}


//AC (1ms, 88KB))
