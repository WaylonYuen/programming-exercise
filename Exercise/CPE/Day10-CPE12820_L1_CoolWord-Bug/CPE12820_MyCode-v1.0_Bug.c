#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

# define bool int
# define True 1
# define False 0

int main(void) {

    int ans = 0;
    char word[10005] = {}; //字串
    int counter[26] = {0}; //字母出現次數統計清單

    //單個字母最高統計次數為100次
    bool flag[100] = {False}; 
    bool notCool = False;

    //Input
    scanf("%s", word);

    //計算字母出現次數
    for (int i = 0; i < strlen(word); i++) {
        counter[(word[i] - 'a')]++;
    }

    //遍歷所有字母
    for (int i = 0; i < 26; i++) {

        //有出現的字母則
        if(counter[i] > 0) {

            //檢查出現字母次數是否重複: 有則
            if(flag[counter[i]] == True) {
                notCool = True;
                break;
            }

            //標記該出現次數已經出現
            flag[counter[i]] = True;
        }
    }
    
    //沒重複出現則有效
    if(!notCool) { ans++; }

    printf("Case 1 : %d\n", ans);

    return 0;
}