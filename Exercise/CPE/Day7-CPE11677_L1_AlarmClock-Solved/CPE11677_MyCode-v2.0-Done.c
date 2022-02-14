// 16：23 28
#include <stdio.h>

int main(void) {

    int h1, m1, h2, m2;

    while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2)) {
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) { break; }
        int ans = (h1 > h2 || (h1 == h2 && m1 > m2))
            ? 1440 - ((h1 * 60 + m1) - (h2 * 60 + m2))
            : (h2 * 60 + m2) - (h1 * 60 + m1);
        printf("\t\t\t%d\n", ans);
    }

    return 0;
}