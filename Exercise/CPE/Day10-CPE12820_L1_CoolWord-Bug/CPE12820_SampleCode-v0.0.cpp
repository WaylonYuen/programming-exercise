//uva12820
#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    int n, s, t, i, j, k;
    char c;

    s = 1;
    while(scanf("%d", &n) != EOF){
    	getchar();
        t = 0;
        while(n--) {

            int num[26] = {0};
            bool ans[30] = {};

            while(scanf("%c", &c) != EOF) {
            	if(c == '\n') { break; }
                num[c - 'a']++;
            }

            for(i = 0, j = 0, k = 0; i < 26; i++) {

                
                if(num[i]) {
                    j++; //統計是否超過一個字母
                    //標記出現次數是否出現過
                    if(ans[num[i]]) {
                        k = 1;
                        printf("\t\tTest[%d] -> ansFlag[%d]:%d  counter1:%d  j:%d\n", i, num[i], ans[num[i]], num[i], j);
                        break;
                    }
                    
                    //標記該出現次數
                    ans[num[i]] = 1;

                    printf("\t\tTest[%d] -> ansFlag[%d]:%d  counter2:%d  j:%d\n", i, num[i], ans[num[i]], num[i], j);
                }
            }

            printf("k : %d\n", k);

            if(k == 0 && j != 1) { t++; }

        }

        printf("Case %d: %d\n", s++, t);
    }
    return 0;
}

//1、