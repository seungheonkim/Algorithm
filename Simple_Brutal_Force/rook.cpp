//
// Created by 김승헌 on 2022/07/23.
//
#include <stdio.h>

int board[8][8];
int rook_x[2], rook_y[2], rookCnt = 0;
int rx, ry;

int main() {

    //보드의 말 위치 입력
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    //룩의 좌표값 룩 배열에 저장
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 2) {
                //0번째에 넣어주고 난후 다음 index 넘어가기 위한 ++ 처리
                rook_x[rookCnt] = i;
                rook_y[rookCnt] = j;
                rookCnt++;
            }
        }
    }

    //룩 기준 상, 하, 좌, 우 킹 을 만나는지 막히는지 확인

    bool flag = false; // 만나면 true

    for (int i = 0; i < rookCnt; i++) {
        rx = rook_x[i];
        ry = rook_y[i];

        //상
        for (int j = rx - 1; j >= 0; j--) {
            if (board[j][ry] == 1)flag = true;
            else if (board[j][ry] == 3) break;
        }

        //하
        for (int j = rx + 1; j < 8; j++) {
            if (board[j][ry] == 1)flag = true;
            else if (board[j][ry] == 3) break;
        }

        //좌
        for (int j = ry - 1; j >= 0; j--) {
            if (board[rx][j] == 1)flag = true;
            else if (board[rx][j] == 3) break;
        }

        //우
        for (int j = ry + 1; j < 8; j++) {
            if (board[rx][j] == 1)flag = true;
            else if (board[rx][j] == 3) break;
        }
    }

    if (flag == true) printf("1");
    else printf("0");

    return 0;
}
