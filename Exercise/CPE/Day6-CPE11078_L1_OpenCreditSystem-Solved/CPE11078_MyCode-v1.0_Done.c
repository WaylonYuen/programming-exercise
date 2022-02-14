//T18:22
//T18:39
//耗時 17mins
#include <stdio.h>

int studentScore[100000] = {0};
int ans[21] = {0};

int counter = 0;

int main(void) {

    int dataNum = 0;
    scanf("%d", &dataNum);
    //printf("Debug => data number: %d\n", dataNum);

    for (int i = 0; i < dataNum; i++) {
        int dataSize = 0;
        scanf("%d", &dataSize);
        //printf("Debug => data size: %d\n", dataSize);

        for (int i = 0; i < dataSize; i++) {
            scanf("%d", &studentScore[i]);
        }
        //Tests
        // puts("");
        // for (int i = 0; i < dataSize; i++) {
        //     printf("Tests: studentScore[%d] = %d\n", i, studentScore[i]);
        // }
        
        
        int maxSD = -999999;

        //小減大也會一併計算，但這只會越減越小
        // //puts("");
        // for (int i = 0; i < dataSize-1; i++) {
        //     //printf("data[%d]\n", i);
        //     for (int j = i+1; j < dataSize; j++) {
        //         int sd_tmp = studentScore[i] - studentScore[j];
        //         //printf("Tests: [i:%d]%d - [j:%d]%d = %d\n", i, studentScore[i], j, studentScore[j], sd_tmp);
        //         if(maxSD < sd_tmp) { 
        //             maxSD = sd_tmp;
        //         }
        //         counter++;
        //     }
        // }

        //優化
        int current = studentScore[0];
        for (int i = 1; i < dataSize; i++) {
            if(current - studentScore[i] > maxSD) {
                maxSD = current - studentScore[i];
            }

            //小減大則數值會很小，所以沒必要算
            if(current < studentScore[i]) {
                current = studentScore[i];
            }
            counter++;
        }


        ans[i] = maxSD;
    }

    puts("\nOuput");
    for (int i = 0; i < dataNum; i++) {
        printf("%d\n", ans[i]);
    }
    
    printf("Counter: %d", counter);

    

    return 0;
}