//
// Created by 김승헌 on 2022/07/29.
//
#include <stdio.h>

int myBingo[5][5];

int main() {

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &myBingo[i][j]);
        }
    }

    int order = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int answer;

            scanf("%d", &answer);
            order++;

            for (int k = 0; k < 5; ++k) {
                for (int p = 0; p < 5; ++p) {
                    if (myBingo[k][p] == answer) {
                        myBingo[k][p] = -1;
                    }
                }
            }

            int cnt = 0;
            //가로줄
            for (int k = 0; k < 5; ++k) {
                int Xcnt = 0;
                for (int p = 0; p < 5; ++p) {
                    if (myBingo[k][p] == -1) {
                        Xcnt++;
                    }
                    if (Xcnt == 5) cnt++;
                }
            }

            //세로줄
            for (int k = 0; k < 5; ++k) {
                int Ycnt = 0;
                for (int p = 0; p < 5; ++p) {
                    if (myBingo[p][k] == -1) {
                        Ycnt++;
                    }
                    if (Ycnt == 5) cnt++;
                }
            }

            //우하향 대각선
            if (myBingo[0][0] == -1 &&
                myBingo[1][1] == -1 &&
                myBingo[2][2] == -1 &&
                myBingo[3][3] == -1 &&
                myBingo[4][4] == -1)
                cnt++;

            //좌하향 대각선
            if (myBingo[0][4] == -1 &&
                myBingo[1][3] == -1 &&
                myBingo[2][2] == -1 &&
                myBingo[3][1] == -1 &&
                myBingo[4][0] == -1)
                cnt++;

            if (cnt >= 3) {
                printf("%d\n", order);
                return 0;
            }
        }
    }
    return 0;
}