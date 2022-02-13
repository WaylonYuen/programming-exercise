//TimothyLiu08 BigBombs 大炸彈

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_CACHE_SIZE 100

//Coordinate
#define X 0
#define Y 1

//Analyze var
int destroyCounter = 0;
int searchTime = 0;
int cacheMaxLength = 0;

int map[MAP_SIZE][MAP_SIZE] = {0};

//Stack
int top = 0;
int stack[MAX_CACHE_SIZE][2] = {0};

//目標位置
int target_row, target_col;
//當前位置
int current_col, current_row;

int directions[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

void Push(int x, int y) {
    stack[top][X] = x;
    stack[top][Y] = y;
    top++;
}

void Pop(int* x, int* y) {
    top--;
    *x = stack[top][X];
    *y = stack[top][Y];
    destroyCounter++; //Analyze
}

int Direction(int* x, int* y, int dir) {
    //移動方向：當前坐標 + 坐標偏移值
    *x = current_col + directions[dir][X];
    *y = current_row + directions[dir][Y];
    searchTime++;

    //該方向是否在地圖範圍內
    return (*x >= 0 && *x < MAP_SIZE) && (*y >= 0 && *y < MAP_SIZE);
}

int main(void) {
    printf("Program  -> Big Bombs -> run...\n");

    //隨機生成地圖
    srand(time(NULL));
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = rand() % 2;
            if(map[i][j] != 0)
                printf("%d ", map[i][j]);
            else
                printf("  ");
        }
        puts("");
    }

    //row:y, col:x
    printf("\nPlz input x & y: ");
    scanf("%d %d", &target_col, &target_row);
    //Input:安全性檢查
    if(target_col < 0 && target_col > MAP_SIZE && target_row < 0 && target_row > MAP_SIZE) {
        printf("Error: row & col should be positive number -> row:%d, col:%d\n", target_row, target_col);
        return 0;
    }

    Push(target_col, target_row);

    //Calculate
    while(top > 0) {
        Pop(&current_col, &current_row);

        //爆破當前坐標
        map[current_row][current_col] = 8;

        //讀取四個方向(上下左右)
        for (int i = 0; i < (sizeof(directions)/sizeof(*directions)); i++) {
            int dir_col, dir_row;
            if(Direction(&dir_col, &dir_row, i)) {
                //該位置是否會被引爆
                if(map[dir_row][dir_col] == 1) {
                    Push(dir_col, dir_row);
                }
            }
        }

        //Analyze
        if(cacheMaxLength < top) {
            cacheMaxLength = top;
        }

    }

    //Ouput
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if(map[i][j] != 0)
                printf("%d ", map[i][j]);
            else
                printf("  ");
        }
        puts("");
    }

    //分析
    printf("Analyze ->\n"
        "\tTotal destroy: %d\n"
        "\tSearch time: %d / 4 = round(total destroy)\n"
        "\tCache Max Length: %d\n", destroyCounter, searchTime, cacheMaxLength);

    puts("End of run...\n");
    return 0;
}