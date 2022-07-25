//
// Created by 김승헌 on 2022/07/25.
//
#include <stdio.h>

int data[100] = {0,};
int n;

int getFibo(int x) {

    data[0] = 0;
    data[1] = 1;

    for (int i = 2; i <= x; ++i) {
        data[i] = data[i - 1] + data[i - 2];
    }

    return data[x];
}

int main() {
    scanf("%d", &n);

    printf("%d", getFibo(n));

    return 0;
}