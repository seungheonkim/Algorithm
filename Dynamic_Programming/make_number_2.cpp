//
// Created by 김승헌 on 2022/07/26.
//
#include <cstdio>

const int MAX = 100010;

int n;
int Table[MAX];
int end;

int getNum(int x) {

    end = 3;

    //base condition
    Table[1] = 1;
    int sum = 0;

    for (int i = 2; i <= end; ++i) {
        sum += Table[i - 1];
        Table[i] = sum + 1;
    }

    //logic
    for (int i = end + 1; i <= n; ++i) {
        for (int j = i - 1; j >= i - end; --j) {
            Table[i] += Table[j];
        }
        Table[i] %= 1000007;
    }

    return Table[x];
}

int main() {
    scanf("%d", &n);

    printf("%d", getNum(n));
}
