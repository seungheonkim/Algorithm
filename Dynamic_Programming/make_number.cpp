//
// Created by 김승헌 on 2022/07/25.
//
#include <cstdio>

using namespace std;

const int MAX = 100;
int n, m;

//data[i] = 1~m 까지의 숫자를 이용해서 숫자 i를 만드는 경우의 수
int Table[MAX];

int main() {

    scanf("%d %d", &n, &m);

    //base condition(기저 조건)
    Table[1] = 1;
    int sum = 0;

    for (int i = 2; i <= m; ++i) {
        sum += Table[i - 1];
        Table[i] = sum + 1;
    }

    //기저 조건 이후의 값 채우기
    for (int i = m + 1; i <= n; ++i) {
        for (int j = i - m; j <= i - 1; ++j) {
            Table[i] += Table[j];
        }
    }

    printf("%d", Table[n]);
    return 0;
}

