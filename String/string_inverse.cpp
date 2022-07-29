//
// Created by 김승헌 on 2022/07/29.
//
#include <cstdio>
#include <cstring>

const int MAX = 1005;

char arr[MAX];
char reverseArr[MAX];

int main() {

    fgets(arr, MAX, stdin);

    int len = strlen(arr);

    for (int i = 0; i < len; ++i) {
        reverseArr[i] = arr[(len - 1) - i];

        printf("%c", reverseArr[i]);
    }

    return 0;
}
