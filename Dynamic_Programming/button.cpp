//
// Created by 김승헌 on 2022/07/26.
//
#include <cstdio>

int getMax(int a, int b) {
    return a > b ? a : b;
}

void getResult(int x, int y, int z) {
    if (x >= y && x >= z) printf("%d", x);
    else if (y >= x && y >= z) printf("%d", y);
    else printf("%d", z);
}

int main() {

    int n;
    scanf("%d", &n);

    int Table[n][3];

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &Table[i][0], &Table[i][1], &Table[i][2]);

        if (i != 0) {
            Table[i][0] = Table[i][0] + getMax(Table[i - 1][1], Table[i - 1][2]);
            Table[i][1] = Table[i][1] + getMax(Table[i - 1][0], Table[i - 1][2]);
            Table[i][2] = Table[i][2] + getMax(Table[i - 1][0], Table[i - 1][1]);
        }
    }

    getResult(Table[n - 1][0], Table[n - 1][1], Table[n - 1][2]);
    return 0;
}
