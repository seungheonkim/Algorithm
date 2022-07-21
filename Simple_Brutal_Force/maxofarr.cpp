//
// Created by 김승헌 on 2022/07/21.
//
#include <cstdio>

const int MAX = 10;

int arr[MAX][MAX];
int maxValue = 0;
int max_i, max_j;

void maxofArr() {

    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            if(maxValue <= arr[i][j]) {
                maxValue = arr[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    printf("%d\n", maxValue);
    printf("%d %d", max_i, max_j);
    return;
}

int main() {
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    maxofArr();

    return 0;
}
