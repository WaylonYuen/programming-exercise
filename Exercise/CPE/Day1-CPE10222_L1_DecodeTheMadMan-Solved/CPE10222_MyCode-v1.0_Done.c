//code time: 1hr

/*分析:
    1、利用參照列表(contrastList)參照標準鍵盤上向左移動兩位的字符 &
    & 作為 Key 以便後續進行索引值的對照來解密。

    2、根據讀取的字元(get)逐個進行解密 &
    & => {
        #1、檢查字元(get)是否為「換行」符號 &
        -> True: 表示該行密文解析完, 進行下一行的新一輪解密。
        { if(get == '\n') => break; }

        #2、檢查字元(get)是否為「空白」符號 &
        -> True: 不需要進行解析。
        { if(get == ' ') => char:decode = get; }

        #3、檢查字元(get)是否在大小寫 與 指定符號的範圍內 &
        & => {
            ##1、小寫:
            通過字元原本的 ASCII十進位減掉'a' &
            & 將其重新定位到 int:0 作為其新的索引值，其他小寫字符以此類推。

            ##2、大寫:
            << 依照題目要求，明文輸出均為小寫。
            >> 因此大寫密文要先通過 'A'-'a' = 32 的差值進行 To lower case。
            tip: 小寫 = 大寫 + 32
            tip: 大寫 = 小寫 - 32
        }
        
        & => {
            ##1 小寫範圍: 
            { if(get >= 97 && get <= 122) =>
                char:decode = contrastListA[get-'a'];
            }

            ##2 大寫範圍:
            { if(get >= 65 && get <= 90) {
                decode = get + 32;
                char:decode = contrastListA[get-'a'];
            } }

            ##3 符號範圍:
            直接根據 contrastList[n][0] 的比對 參照 contrastList[n][1] 獲取明文
        }
    }
*/

#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

#define bool int
#define True 1
#define False 0

int main(void) {
    
    char contrastList[6][2] = {
        { '[', 'o', },
        { ']', 'p', },
        { ';', 'k', },
        { '\'', 'l', },
        { ',', 'n', },
        { '.', 'm', },
    };

    char contrastListA[] = {
     // 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 
     // 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
     // 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 
     // 'y', 'z', 
        'a', 'c', 'z', 'a', 'q', 's', 'd', 'f', 
        'y', 'g', 'h', 'j', 'b', 'v', 'u', 'i', 
        'q', 'w', 's', 'e', 't', 'x', 'w', 'x', 
        'r', 'z', 
    };

    char get;
    char input[1000] = {};
    char output[50][1000] = {};

    int dataSize = 0;
    scanf("%d", &dataSize);
    //printf("\t\tDebug => %d\n", dataSize);
    get = getchar(); //使用getchar()之前使用了scanf()必須消去殘留的\n
    for (int i = 0; i < dataSize; i++) {

        int index = 0;
        //讀取整行字符保存到 input[]中
        while ((get = getchar()) != '\n') {
            input[index++] = get;
        }
        input[index] = '\0'; //將該字元組定義為字串
        //printf("\t\tDebug => %s\n", input);

        //逐個字元讀取
        for (int j = 0; j < strlen(input); j++) {
            get = input[j];

            char decode;
            //特殊處理: 換行符號
            if(get == '\n') {
                break;
            //特殊處理: 空白符號
            } else if(get == ' ') { 
                decode = get;
            //小寫範圍
            } else if(get >= 97 && get <= 122) { 
                //decode = get - 32; //小 - 32 = 大
                decode = contrastListA[get - 'a'];
            //大寫範圍
            } else if(get >= 65 && get <= 90) {
                decode = get + 32; //大 + 32 = 小
                //printf("\t\tdebug => [%d]%c + 32 = %c\n", get, get, decode );
                decode = contrastListA[decode - 'a'];
            //符號範圍
            } else {
                for (int i = 0; i < 6; i++) {
                    if(get == contrastList[i][0]) {
                        decode = contrastList[i][1];
                        break;
                    }
                }
            }
            //保存明文字元
            output[i][j] = decode;
        }
        //將該字元組定義為字串
        output[i][strlen(input)] = '\0';
    }

    //輸出結果
    for (int i = 0; i < dataSize; i++) {
        printf("[%d] %s\n", i, output[i]);
    }

    return 0;
}