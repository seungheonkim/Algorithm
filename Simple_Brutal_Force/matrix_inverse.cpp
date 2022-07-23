//
// Created by 김승헌 on 2022/07/24.
//
#include <stdio.h>

int map[10][10] = {0,};
int n;

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {//뒤집기 횟수

        //대각선의 수 무조건 1로 만들어주기 위해 미리 바꾸기
        map[i][i] = 1;

        for (int j = 0; j < 10; j++) {
            //행 바꾸기
            if (map[i][j] == 0) map[i][j] = 1;
            else if (map[i][j] == 1) map[i][j] = 0;

            //열 바꾸기
            if (map[j][i] == 0) map[j][i] = 1;
            else if (map[j][i] == 1) map[j][i] = 0;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}