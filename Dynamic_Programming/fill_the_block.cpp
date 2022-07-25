//
// Created by 김승헌 on 2022/07/25.
//
#include <stdio.h>

int data[100] = {0,};
int n;

int getFibo(int x) {

    data[1] = 1;
    data[2] = 2;

    for (int i = 3; i <= x; ++i) {
        data[i] = data[i - 1] + data[i - 2];
    }

    return data[x];
}

int main() {
    scanf("%d", &n);

    printf("%d", getFibo(n));

    return 0;
}