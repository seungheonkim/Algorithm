//
// Created by 김승헌 on 2022/07/21.
//
#include <cstdio>

int main() {

    int n;

    scanf("%d", &n);
    int space = n - 1;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < space; j++) {
            printf(" ");
        }

        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }

        for (int j = 0; j < space; j++) {
            printf(" ");
        }
        space--;

        for (int j = 0; j < n-i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}