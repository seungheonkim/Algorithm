//
// Created by 김승헌 on 2022/07/23.
//
#include <stdio.h>

const int MAX = 110;

int canvas[MAX][MAX] = {0,};
int paper[MAX] = {0,};

int n;
int x, y;
int width, height;

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &x, &y, &width, &height);//입력

        for (int j = y; j < y + height; ++j) {
            for (int k = x; k < x + width; ++k) {
                canvas[j][k] = i + 1; // 색칠된 면적 만큼 해당 색종이 번호 붙여서 표시하기
            }
        }
    }

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            paper[canvas[j][i]]++; // 색종이 번호가 동일한 면적이 몇개인지 계산해서 해당 색종이 번호에 저장해놓기
        }
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d\n", paper[i]);
    }

    return 0;
}