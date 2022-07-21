//
// Created by 김승헌 on 2022/07/21.
//
#include <cstdio>

const int MAX = 110;

int n;
int i, j;
int arr[MAX][MAX];
int num = 1;


int main() {

    scanf("%d", &n);

    while (i + j < n) {
        arr[i][j] = num++;

        if (j == 0) {
            j = i + 1;
            i = 0;
        } else {
            i++;
            j--;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n - k; l++) {
            printf("%d ", arr[k][l]);
        }
        printf("\n");
    }


    return 0;
}
