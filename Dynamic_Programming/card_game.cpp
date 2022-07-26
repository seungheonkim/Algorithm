//
// Created by 김승헌 on 2022/07/26.
//
#include <cstdio>

const int MAX = 3;

int n;
int value;
int myMax;

int Table[MAX];

int getMax(int a, int b, int c) {
    if (a >= b && a >= c) myMax = a;
    else if (b >= a && b >= c) myMax = b;
    else myMax = c;

    return myMax;
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);

        if (i == 0) {
            Table[0] = 0;
            Table[1] = value;
            Table[2] = 0;
        } else {
            int max = getMax(Table[0], Table[1], Table[2]); // 그 전 결과들 중 최댓값 max에 저장
            Table[2] = Table[1] + value; // 이전 Table[1]에 저장되어있는 값 이용
            Table[1] = Table[0] + value; // 이전 Table[0]에 저장되어있는 값 이용
            Table[0] = max;
        }
//        printf("%d %d %d\n", Table[0], Table[1], Table[2]);
    }
    printf("%d", getMax(Table[0], Table[1], Table[2]));

    return 0;
}
