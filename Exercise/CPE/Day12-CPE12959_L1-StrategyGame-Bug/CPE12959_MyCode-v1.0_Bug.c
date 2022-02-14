//Error
//12959 Strategy Game

//16:44~16:51
#include <stdio.h>

int main(void) {

    int J; //player number
    int R; //game round

    while (scanf("%d %d", &J, &R)) {
        if(J == 0 && R == 0) { break; }

        int player_totalScore[100] = {0};
        int winner_index = 0;
        int point = 0;

        for (int i = 0; i < J * R; i++) {

            scanf("%d", &point);
            int player_current_index = i % J; //獲得當前玩家索引值
            player_totalScore[player_current_index] += point; //將當前玩家分數累計

            //時刻hold住最高分玩家
            if(player_totalScore[player_current_index] >= player_totalScore[winner_index]) {
                winner_index = player_current_index;
            }

        }
        
        printf("\nAns: %d\n", ++winner_index);
    }

    return 0;
}