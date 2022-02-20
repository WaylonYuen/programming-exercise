// UVa10107 : ZJ c010 : What is the Median? 中位數

/* 問題分析:
    1、輸入的整數 N < 10000筆.
        >> while(scanf != EOF) 作為停止判斷
    2、插入排序法 對資料進行排序.
*/

#include <stdio.h>

#define SWAP(a,b,t) ((t)=(a), (a)=(b), (b)=(t))
#define N 10000

//插入排序法
void InsertSort(int* array, int* len, int num) {
    //容量判斷
    if(*len + 1 >= N) return; //無法添加新資料(已達容量上限)

    //如果比最後一個值還大，直接插入到末端
    if(array[*len-1] < num) {
        array[*len] = num;
    } else {
        int tmp;
        for (int i = 0; i < *len; i++) {
            if(array[i] > num) {
                SWAP(array[i], num, tmp);
            }
        }
        array[*len] = num;
    }
    *len += 1; //長度+1
}

//中位數
int Median(int* array, int len) {
    return (len % 2 == 0) ? (array[(len/2)-1] + array[len/2])/2 : array[len/2];
}

//Program
int main(void) {
    
    int length = 0; //資料長度
    int input = -1; //當前數字
    int container[N] = {0}; //容器

    //first data
    scanf("%d", &input);
    container[length++] = input;
    printf("%d\n", container[length-1]);

    while (scanf("%d", &input) != EOF) {
        InsertSort(container, &length, input); //插入排序
        printf("%d\n", Median(container, length)); //輸出中位數
    }

    return 0;
}

//AC (52ms, 108KB)
