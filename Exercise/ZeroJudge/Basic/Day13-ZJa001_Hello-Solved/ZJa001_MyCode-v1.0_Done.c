// ZJ a001 : Hello 哈囉

/* 問題分析:
    1、輸入的字串最大長度？(題目沒說明)
        <<  參考記憶體限制 512MB, 單一最大Char容量(512*1024*1024 = 536870912B)
        >>  假設 : 字串最大長度 => 0 < x < 536870912, x = 100(假設100擁有長度合理性)
*/

#include <stdio.h>

#define SIZE 100

int main(void) {
    
    char input_str[SIZE] = {};

    scanf("%s", input_str);

    printf("hello, %s", input_str);

    return 0;
}

//測試結果：AC (3ms, 88KB)
