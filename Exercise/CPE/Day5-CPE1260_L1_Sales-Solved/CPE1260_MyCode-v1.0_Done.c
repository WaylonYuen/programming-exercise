//理解題目用了 9mins
//解題花費 40mins

#include <stdio.h>

int main() {

    //資料筆數
    int dataNum = 0;
    scanf("%d\n", &dataNum);

    int ansIndex = 0;
    int ansLen = dataNum;
    int ansList[9999] = {0};

    while (dataNum--) {
        //printf("Tests: %d\n", dataNum);
        int ans = 0;
        int dataLen = 0;
        int datalist[9999] = {0};

        scanf("%d", &dataLen);
        //printf("dataLen: %d\n\n", dataLen);     

        for (int i = 0; i < dataLen; i++) {
            scanf("%d", &datalist[i]);
            if(i == 0) continue;
            for (int j = 0; j < i; j++) {
                if(datalist[j] <= datalist[i]) {
                    ans++;
                }
                //printf("Tests: %d vs %d = %d\n", datalist[j], datalist[i], ans);
            }
            //puts("end\n");
        }
        
        ansList[ansIndex++] = ans;
    }

    //output
    puts("");
    for (int i = 0; i < ansLen; i++) {
        printf("ans[%d]: %d\n", i, ansList[i]);
    }
    

    return 0;
}