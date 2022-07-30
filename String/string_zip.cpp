//
// Created by 김승헌 on 2022/07/30.
//
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX = 1005;

char Arr[MAX];

int main() {

    scanf("%s", Arr);

    int len = strlen(Arr);
    int cnt = 1;

    for (int i = 1; i < len; ++i) {
        if (Arr[i] == Arr[i - 1]) cnt++; // 동일한 알파벳 존재시 갯수하나 증가시킴
        else {
            if (cnt >= 2) printf("%d", cnt); // 갯수 2개 이상이면 cnt 먼저 출력
            printf("%c", Arr[i - 1]); // 그리고 해당 알파벳 출력

            cnt = 1; // 초기화
        }
    }

    return 0;
}
