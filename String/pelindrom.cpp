//
// Created by 김승헌 on 2022/07/29.
//
#include <cstdio>
#include <cstring>

const int MAX = 1005;

char Arr[MAX];

int main() {

    fgets(Arr, MAX, stdin);

    int len = strlen(Arr);

    for (int i = 0; i < len; ++i) {
        if (Arr[i] != Arr[(len - 1) - i]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
