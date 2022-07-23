//
// Created by 김승헌 on 2022/07/21.
//
#include <stdio.h>

const int Max = 1005;

int student[Max][5];
int n;
int result = -1, resultNum;
int sameClass;


int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 5; ++j) {
            scanf("%d", &student[i][j]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        sameClass = 0;
        for (int j = 1; j <= n; ++j) {

            if (i == j) continue;

            if (student[i][1] == student[j][1] ||
                student[i][2] == student[j][2] ||
                student[i][3] == student[j][3] ||
                student[i][4] == student[j][4] ||
                student[i][5] == student[j][5]) sameClass++;

            if(result <= sameClass) {
                result = sameClass;
                resultNum = i;
            }
        }
    }

    printf("%d", resultNum);

    return 0;
}