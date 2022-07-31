//
// Created by 김승헌 on 2022/07/31.
//
#include <cstdio>

const int MAX = 1005;

int n, r;
char Arr[MAX];
bool check[MAX] = {0,};

void Permutation(int x) { // 순열 구하기 함수
    if (x >= r) printf("%s\n", Arr); // 들어가는 수가 주어진 r 이상이되면 해당 조건을 만족하므로 결과 출력
    else {
        for (int i = 0; i < n; ++i) {
            char alphabet = 'a' + i; // alphabet 첫번째 꺼 부터 순서대로 설정
            if (!check[i]) { // 만약 체크를 한적이 없다면
                Arr[x] = alphabet; // 해당 Arr 에 해당 알파벳을 넣고
                check[i] = true; // 체크를 해준다

                Permutation(x + 1); // 그리고 그다음 칸으로 넘어간다
                check[i] = false; // 그 해당 칸은 다시 체크 안한 상태로 만들어주고
                Arr[x] = 0; // 초기값인 0을 넣어놓고 다시 재귀를 돌리는 형식
            }
        }
    }
}

int main() {

    scanf("%d %d", &n, &r);

    Permutation(0);

    return 0;
}