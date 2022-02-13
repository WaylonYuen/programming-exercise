//118 Mutant Flatworld Explorers 突變平面世界探險者

//# define DEBUG
# define DEBUG_PASS 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define bool int
# define True 1
# define False 0

//地圖大小
int mapSize_x, mapSize_y;

//轉向
void Transfer(char* direct, char* cmd) {

    char dir[4] = {'N', 'E', 'S', 'W'};

    int index = -1;
    for (int i = 0; i < sizeof(dir); i++) {
        if(*direct == dir[i]) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Error => Transfer(): Undefined direct!");
    }

    switch (*cmd) {
        case 'L':
            index--;
            if(index < 0) index = sizeof(dir)-1;
            break;
        case 'R':
            index++;
            if(index > sizeof(dir)-1) index = 0;
            break;
        default:
            printf("Error => Transfer(): Undefined cmd!");
            break;
    }

#if defined (DEBUG) && DEBUG_PASS
    printf("Debug => %c transfer to(%c) %c\n", *direct, *cmd, dir[index]);
#endif

    //更新方向
    *direct = dir[index];
}

//只處理移動
bool Moving(int *current_x, int *current_y, char *direct) {
    
    int x, y;
    bool isLost = False;

    switch (*direct) {
        case 'N': x = 0; y = 1; break;
        case 'E': x = 1; y = 0; break;
        case 'S': x = 0; y = -1; break;
        case 'W': x = -1; y = 0; break;
        default:
            printf("Error => Moving(): Undefined direct!\n");
            return True;
    }

    int tmp_x = *current_x + x;
    int tmp_y = *current_y + y;

    //邊界判斷
    isLost = (tmp_x > mapSize_x || tmp_y > mapSize_y || tmp_x < 0 || tmp_y < 0)
        ? True : False;

#if defined (DEBUG) && DEBUG_PASS
    printf("Debug => location(%d, %d, %c) to Target(%d, %d, %c) -> isLost: %d\n",
        *current_x, *current_y, *direct, tmp_x, tmp_y, *direct, isLost);
#endif 

    if(!isLost) {
        *current_x = tmp_x;
        *current_y = tmp_y;
    }

    return isLost;
}

//Program
int main(void) {

    //因應題目要求: 坐標範圍最大不超過(50,50),因此不會超過兩位數
    //*** 兩位數的最小 size = 3(包含結尾符號: \0)
    char str_mapSize_x[3] = {};
    char str_mapSize_y[3] = {};

    //輸入: 地圖大小
    scanf("%s %s", str_mapSize_x, str_mapSize_y); //Input: Line 1
    mapSize_x = atoi(str_mapSize_x);
    mapSize_y = atoi(str_mapSize_y);
#if defined (DEBUG) && DEBUG_PASS
    printf("Debug => Map size: (%s,%s)\n", str_x, str_y);
#endif

    //當前坐標位置 & 方向
    int x, y;
    char str_current_x[3] = {};
    char str_current_y[3] = {};
    char str_direct = ' ';

    int dataIndex = 0;
    char result[100][50] = {};

    //持續讀取
    while(True) {

        scanf("%s", str_current_x);
        if(str_current_x[0] == 'z') break;

        //輸入: 當前坐標 & 面向
        //scanf("%s %s %c", str_current_x, str_current_y, &str_direct); //Input: Line 2
        scanf(" %s %c", str_current_y, &str_direct); //Input: Line 2
        x = atoi(str_current_x);
        y = atoi(str_current_y);
#if defined (DEBUG) && DEBUG_PASS
        printf("Debug => location and direct: (%s, %s, %c)\n", str_current_x, str_current_y, str_direct);
#endif

        //輸入: 指令字串
        //因應題目要求:指令不會超過100個
        char str_cmd[101] = {};
        scanf("%s", str_cmd); //Input: Line 3
#if defined (DEBUG) && DEBUG_PASS
        printf("Debug => command: (%s)\n", str_cmd);
#endif

        int isLost = False;
        for (int i = 0; i < strlen(str_cmd); i++) {
            if(str_cmd[i] == 'R' || str_cmd[i] == 'L') {
                Transfer(&str_direct, &str_cmd[i]);
            } else {
                isLost = Moving(&x, &y, &str_direct);
                if(isLost) break;
            }
        }
#if defined (DEBUG) && DEBUG_PASS
        printf("%d %d %c %d\n", x, y, str_direct, isLost);
#endif

        //整數 to 字串
        sprintf(str_current_x, "%d", x);
        sprintf(str_current_y, "%d", y);
        //結果格式化
        strcat(result[dataIndex], str_current_x);
        strcat(result[dataIndex], " ");
        strcat(result[dataIndex], str_current_y);
        strcat(result[dataIndex], " ");
        //方位
        size_t current_dataLen = strlen(result[dataIndex]);
        result[dataIndex][current_dataLen] = str_direct;
        result[dataIndex][current_dataLen+1] = '\0';

        if(isLost) { strcat(result[dataIndex], " LOST"); }
        
        dataIndex++;
    }

    //輸出結果
    puts("\nOutput:");
    for (int i = 0; i < dataIndex; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}