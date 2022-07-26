//
// Created by 김승헌 on 2022/07/26.
//
#include <cstdio>

const int MAX = 1005;

int Map[MAX][MAX];
int Table[MAX][MAX];
int n, m;

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &Map[i][j]);
        }
    }

    //(0,0) 값 설정
    Table[0][0] = Map[0][0];
    //오른쪽 방향 축
    for (int i = 1; i < m; ++i) {
        Table[0][i] = Table[0][i - 1] + Map[0][i];
    }
    //아래쪽 방향 축
    for (int i = 1; i < n; ++i) {
        Table[i][0] = Table[i - 1][0] + Map[i][0];
    }
    //축(사이드) 를 제외한 가운데 부분은 아래에서 내려오는 값과 오른쪽에서 오는 값비교
    //비교 후 큰 값을 Map[i][j] 값과 더하는 로직
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (Table[i - 1][j] > Table[i][j - 1]) { // 아래에서오는 값이 오른쪽에서 오는 값보다 클때
                Table[i][j] = Table[i - 1][j] + Map[i][j];
            } else {//오른쪽에서 오는 값이 아래에서 오는 값보다 크거나 같을때
                Table[i][j] = Table[i][j - 1] + Map[i][j];
            }
        }
    }
    printf("%d", Table[n - 1][m - 1]);

    return 0;
}
