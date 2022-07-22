//
// Created by 김승헌 on 2022/07/21.
//
#include <stdio.h>

int arr[7][7];

void offset() {
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {

            if (arr[i][j] < arr[i - 1][j] &&
                arr[i][j] < arr[i + 1][j] &&
                arr[i][j] < arr[i][j - 1] &&
                arr[i][j] < arr[i][j + 1]) {
                printf("* ");
            } else {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}


int main() {

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            arr[i][j] = 10;
        }
    }

    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    offset();

    return 0;
}
