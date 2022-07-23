//
// Created by 김승헌 on 2022/07/23.
//
#include <stdio.h>

const int Max = 105;

int map[Max][Max] = {0,};
int n;
int x, y, r;

int main() {

    scanf("%d", &n);
    scanf("%d %d %d", &x, &y, &r);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {

            int dix = x - i;
            int diy = y - j;

            if (dix < 0) dix *= -1;
            if (diy < 0) diy *= -1;

            int dist = dix + diy;

            if (dist == 0) map[i][j] = -1;
            else if (dist <= r) map[i][j] = dist;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {

            if (map[i][j] == -1) printf("x ");
            else printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
