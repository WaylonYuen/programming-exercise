//參考: v0.0

/*分析:

    1、優化了對照表(char[]:key)
    直接根據標準鍵盤鍵位作為參照，無需再計算字元ASCII十進位及重新指向新索引值，直接通過 key-2
    的方式獲得明文。
    => 好處：程式邏輯更清晰易懂
*/

/*問題:

    1、已知 BUG:

        BUG_1: 根據(char[]:key)的索引值範圍，未對 q、w 進行索引值下限的處理。
        >> 因此解析時會發生溢位的錯誤。
        { 'q' => key[0] => char:decode = key[0-2] //Error: Out of range  }
        !! 不處理的原因: 密文中沒有包含上述字符。

        BUG_2: 如果密文中包含 q、w、a、s、z、x 則無法解析。
        << 因為解析時索引值所指向的內容是錯誤的。
        => q、w 的情況，參考 BUG #1。
        => a、s、z、x 的情況，如下(以'a'做例子)
        { 'a' => key[13] => char:decode = '[' = key[13-2] }
        !! 不處理的原因: 密文中沒有包含上述字符。

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define True 1
#define False 0

int main(void) {
    
    char key[] = {"qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"};
    
    char outputList[20][500] = {}; //假設最多只有20筆資料，每筆資料長度最長500個字元(包含字串結束符\0)

    char get;
    int dataNum = 0;

    scanf("%d", &dataNum);
    get = getchar(); //使用getchar()之前使用了scanf()必須消去殘留的\n
    for (int i = 0; i < dataNum; i++) {

        int index = 0;
        while ((get = getchar()) != '\n') {

            if('A' <= get && get <= 'Z') {
                get += 32; //to lower case
            }

            if(get == ' ') {
                outputList[i][index++] = get;
            } else {
                for (int j = 0; j < strlen(key); j++) {
                    if(get == key[j]) {
                        outputList[i][index++] = key[j-2];
                    }
                }
            }

        }
        outputList[i][index] = '\0';
    }

    puts("\n>>>> Output >>>>");
    for (int i = 0; i < dataNum; i++) {
        printf("[%d] %s\n", i, outputList[i]);
    }
    puts("End of run...\n");

    return 0;
}