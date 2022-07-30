//
// Created by 김승헌 on 2022/07/30.
//
#include <cstdio>
#include <cstring>

const int MAX = 1005;

char A[MAX], B[MAX];

int main() {

    fgets(A, MAX, stdin);
    fgets(B, MAX, stdin);

    int lenA = strlen(A);
    int lenB = strlen(B);

    for (int i = 0; i < lenA - lenB; i++) {
        int cnt = 0;

        for (int j = 0; j < lenB; j++) {
            if (A[i + j] == B[j]) {
                cnt++;
            }
        }

        if (cnt == lenB) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}