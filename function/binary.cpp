//
// Created by 김승헌 on 2022/08/01.
//
#include <cstdio>

int n;

void getBinary(int x) {
    if (x == 0) return;
    else {
        getBinary(x / 2); // 계속 2로 나누면서 몫을 또 2로 나눔
        printf("%d", x % 2); // 출력은 2로 나눈 나머지를 순서대로 출력
    }
}

int main() {
    scanf("%d", &n);

    getBinary(n);

    return 0;
}