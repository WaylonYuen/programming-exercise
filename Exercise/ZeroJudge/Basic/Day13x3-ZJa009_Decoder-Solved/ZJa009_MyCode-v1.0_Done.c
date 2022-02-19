// ZJ a009 : Decoder 解碼器

/* 問題分析:
    1、根據題目要求, 參照Sample Input及Sample Output推出的 Key = 7.
    2、輸入的字串最大長度？(題目沒說明)
        <<  參考記憶體限制 512MB, 單一最大Char容量(512*1024*1024 = 536870912B)
        >>  字串最大長度 => 0 < x < 536870912
        >>  假設 : x = 100(假設100擁有長度合理性) => 錯誤 RE(空間溢位)
        >>  假設 : x = 1000(假設1000擁有長度合理性) => 通過 AC
*/

#include <stdio.h>
#include <string.h>

#define KEY 7

int main(void) {

    char input[1000] = {};

    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        printf("%c", input[i] - KEY); //Decode -7, Encryp +7
    }

    return 0;
}

//AC (2ms, 96KB)
