//
// Created by 김승헌 on 2022/07/26.
//
#include <cstdio>

const int MAX = 1000010;

bool Table[MAX]; //false = 지는 경우 / true = 이기는 경우
int n;

int main() {

    scanf("%d", &n);

    Table[1] = true;
    Table[2] = true;
    Table[3] = true;

    for (int i = 4; i <= n; ++i) {
        if (Table[i - 1] && Table[i - 2] && Table[i - 3]) Table[i] = false;//이전 3개가 true 로 다 이기면 i 일때는 무조건 짐
        else Table[i] = true;
    }

    if (Table[n]) printf("YES");
    else printf("NO");

    return 0;
}
