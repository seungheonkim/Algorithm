//
// Created by 김승헌 on 2022/07/21.
//
#include <cstdio>

int n;
int a, b, c;
int prize, maxPrize;


int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);

        if (a == b && b == c && c == a) {
            prize = 10000 + a * 1000;
        } else if (a != b && b != c && c != a) {
            if (a > b && a > c) prize = a * 100;
            else if (b > a && b > c) prize = b * 100;
            else prize = c * 100;
        } else {
            if (a == b && a != c) prize = 1000 + a * 100;
            else if (b == c && b != a) prize = 1000 + b * 100;
            else prize = 1000 + c * 100;
        }

        if (maxPrize <= prize) maxPrize = prize;
    }

    printf("%d", maxPrize);
    return 0;
}
