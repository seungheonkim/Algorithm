//
// Created by 김승헌 on 2022/07/29.
//
#include <cstdio>

const int MAX = 105;

int n;
int info[MAX][3];
// info[][0] : 생각한 수
// info[][1] : strike 수
// info[0][2] : ball 수

int result = 0; // 생각한 조건을 만족하는 숫자 조합 갯수

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &info[i][0], &info[i][1], &info[i][2]);
    }

    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            for (int k = 1; k <= 9; ++k) {
                if (i != j && j != k && k != i) { // 각자릿수 모두 달라야함
                    bool flag = false; // true 이면 조건 불만족

                    for (int l = 0; l < n; ++l) {
                        int first = info[l][0] / 100; // 100의 자리
                        int second = (info[l][0] / 10) % 10; // 10의 자리
                        int third = info[l][0] % 10; // 1의 자리

                        int strike = 0, ball = 0;

                        //strike 조건
                        if (first == i) strike++;
                        if (second == j) strike++;
                        if (third == k) strike++;

                        //ball 조건
                        if (second == i || third == i) ball++;
                        if (first == j || third == j) ball++;
                        if (second == k || first == k) ball++;

                        // 아예 현재 생각하고 있는 조건에 벗어나고 있으면 flag = true;
                        if (info[l][1] != strike || info[l][2] != ball) flag = true;
                    }
                    if (!flag) result++;
                }
            }
        }
    }
    printf("%d", result);

    return 0;
}