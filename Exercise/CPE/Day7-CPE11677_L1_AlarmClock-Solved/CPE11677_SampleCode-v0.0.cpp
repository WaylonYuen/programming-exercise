//uva11677
#include <iostream>
using namespace std;

int main() {

    int h1, m1, h2, m2;

    while((cin >> h1 >> m1 >> h2 >> m2)) {
        if(h1 == m1 && m1 == h2 && h2 == m2 && m2 == 0) { break; }
        int ans = (h1 > h2 || (h1 == h2 && m1 > m2))
            ? 1440 - ((60 * h1 + m1) - (60 * h2 + m2)) //反向減
            : (60 * h2 + m2) - (60 * h1 + m1); //正向減
        cout << "\t\t\t" << ans << endl;
    }

    // while((cin >> h1 >> m1 >> h2 >> m2)) {
    //     if(h1 == m1 && m1 == h2 && h2 == m2 && m2 == 0) { break; }

    //     //跨日 || 小時相同 && 分鐘反追
    //     //跨日 和 反追要特別計算
    //     if(h1 > h2 || (h1 == h2 && m1 > m2)) {

    //         //一日分鐘 = 1440mins
    //         //直接換算成分鐘相減計算
    //         cout << 1440 - ((60 * h1 + m1) - (60 * h2 + m2)) << endl;
        
    //     //
    //     } else {
    //         cout << (60 * h2 + m2) - (60 * h1 + m1) << endl;
    //     }
    // }

    
    
    return 0;
}