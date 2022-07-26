//
// Created by 김승헌 on 2022/07/26.
//
#include <cstdio>

const int MAX = 100010;

int n;
int Table[MAX];

int getMin(int a, int b) {
    return a > b ? b : a;
}

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        Table[i] = 999999999;

        for (int j = 1; j <= n; ++j) {

            if (i - (j * j) < 0) break;
            else if (i == j * j) Table[i] = 1;
            else {
                Table[i] = getMin(Table[i], Table[i - (j * j)] + 1);
            }
        }
    }

    printf("%d", Table[n]);
    return 0;
}
