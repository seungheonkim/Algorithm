//
// Created by 김승헌 on 2022/07/29.
//
#include <cstdio>
#include <cstring>

const int MAX = 100010;

char homework[MAX];

int main() {

    fgets(homework, MAX, stdin);

    int len = strlen(homework);

    for (int i = 0; i < len; ++i) {
        if (homework[i] == ' ') printf("");
        else printf("%c", homework[i]);
    }
    return 0;
}