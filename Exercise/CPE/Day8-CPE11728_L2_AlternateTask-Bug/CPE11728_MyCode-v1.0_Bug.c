//15:20 ～ 15:24

//15:28

#include <stdio.h>

void FactorGame(int input) {
    
    //input < 1000

    int ansIndex = 0;
    int ansList[9999] = {0}; 
    int sumOfAns = 0;

    //紀錄因數
    for (int i = input; i >= 1; i--) {
        printf("Test: %d / %d\n", input, i);
        if(input%i == 0) {
            int result = input/i;
            ansList[ansIndex++] = result;
            sumOfAns += result;
        }
    }
    printf("\nIndex: %d\nsum of Ans: %d\n\n", ansIndex, sumOfAns);

    
    //output All
    for (int i = 0; i < ansIndex; i++) {
        printf("%d\n", ansList[i]);
    }
    puts("");

    //一頭一尾減，判斷與目標的差距是變大還是變小

    if(ansIndex != 1) {
        sumOfAns -= input;
        for (int i = 0; i < ansIndex; i++) {
            printf("Test: %d - %d\n", sumOfAns, ansList[i]);

            if(sumOfAns > input) {
                sumOfAns -= ansList[i];
            } else {
                break;
            }
        }
    }
    

    printf("ans: %d", sumOfAns);
    

}


int main(void) {
    
    FactorGame(997);

    return 0;
}