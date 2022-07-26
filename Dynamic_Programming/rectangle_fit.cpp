//
// Created by 김승헌 on 2022/07/26.
//
#include <cstdio>

const int MAX = 105;

int n;
int Table[MAX];

int Rect(int x) {

    Table[1] = 1;
    Table[2] = 2;

    for (int i = 3; i <= n; ++i) {
        Table[i] = (Table[i - 1] + Table[i - 2]) % 1000007;
    }

    return Table[x];
}


int main() {
    scanf("%d", &n);

    printf("%d", Rect(n));
}
