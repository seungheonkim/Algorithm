//
// Created by 김승헌 on 2022/07/21.
//
#include <cstdio>

const int MAX = 105;

int n;
int myAnswer[MAX] = {0,};
int score[MAX] = {0,};
int sum = 0;

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &myAnswer[i]);
    }

    for (int i = 0; i < n; i++) {

        if (i == 0) {
            if (myAnswer[i] == 0) score[i] = 0;
            else score[i] = 1;
        } else {

            if (myAnswer[i - 1] == 0 && myAnswer[i] == 1) {
                score[i] = 1;
            } else if (myAnswer[i - 1] == 1 && myAnswer[i] == 1) {
                score[i] = score[i - 1] + 1;
            }
        }

        sum += score[i];
    }

    printf("%d", sum);

    return 0;
}