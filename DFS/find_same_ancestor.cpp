//
// Created by 김승헌 on 2022/07/22.
//
#include <stdio.h>

const int MAX = 1005;

int parent[MAX];
bool check[MAX];

int n, x, y;

int main() {

    scanf("%d %d %d", &n, &x, &y);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;

        scanf("%d %d", &a, &b);

        parent[b] = a;
    }

    while (true) {
        check[x] = true;

        if (x == 0) break;

        x = parent[x];
    }

    while (true) {
        if (check[y] == true) {
            printf("%d", y);
            break;
        } else {
            check[y] = true;
            y = parent[y];
        }
    }
    return 0;
}