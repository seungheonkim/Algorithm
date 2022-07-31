//
// Created by 김승헌 on 2022/08/01.
//
#include <cstdio>

const int MAX = 100;

int n;

int getFactorial(int x) { // 팩토리얼 함수
    if (x == 0) return 1; // 기저조건인 0일때 0! = 1로 정해져있음
    else return x * getFactorial(x - 1); // 이 외의 수는 n * getFactorial(n-1) 로 재귀함수 실행
}

int main() {
    scanf("%d", &n);

    printf("%d", getFactorial(n));

    return 0;
}
