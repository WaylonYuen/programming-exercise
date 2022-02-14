//Apple Peeler 蘋果削皮器

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define True 1
#define False 0

int main(void) {

    int array[4][4] = {
        {  1,  2,  3, 4, },
        { 12, 13, 14, 5, },
        { 11, 16, 15, 6, },
        { 10,  9,  8, 7, },
    };

    //下限
    int row = 0;
    int column = 0;

    //上限
    int width = 4;
    int height = 4;

    while (True) {
        
        //向右
        if(width == 0 || height == 0) break;
        for (int c = column; c < (column + width); c++)
            printf("%d ", array[row][c]);
        row++;
        height--;

        //向下
        if(width == 0 || height == 0) break;
        for (int r = row; r < height; r++)
            printf("%d ", array[r][column + (width - 1)]);
        width--;

        //向左
        if(width == 0 || height == 0) break;
        for (int c = (column + (width - 1)); c >= column; c--)
            printf("%d ", array[row + (height - 1)][c]);
        height--;

        //向上
        if(width == 0 || height == 0) break;
        for (int r = row + (height - 1); r >= row; r--)
            printf("%d ", array[r][column]);
        column++;
        width--;

    }

    return 0;
}