//uva11728
#include <cmath>
#include <iostream>

using namespace std;

int main() {

    // brute force
    // enumerate all the situations
    int table[1005];

    //初始化為 -1;
    for (int i = 0; i < 1005; ++i)
        table[i] = -1;


    for (int i = 1; i <= 1000; ++i) {

        int tmp = 0;
        for (int j = 1; j <= sqrt(i); ++j) {
    
            if (i % j == 0) {
                if (i != j * j)
                tmp += i / j;
                tmp += j;
            }
        }

        if (tmp <= 1000) {
            table[tmp] = i;
            printf("Tests: table[%d] = %d, sum: %d\n", i, table[tmp], tmp);
        }
    }

    for (int i = 0; i < 1000; i++) {
        printf("Tests: table[%d] = %d\n", i, table[i]);
    }
    

    int n;
    int cnt = 1;
    while (cin >> n && n) {
        cout << "Case " << cnt << ": " << table[n] << " -> "<< n << endl;
        ++cnt;
    }

  return 0;
}