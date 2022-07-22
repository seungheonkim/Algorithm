//
// Created by 김승헌 on 2022/07/20.
//
#include <stdio.h>

const int MAX = 1001;

int n, m;
int maze[MAX][MAX];
int route[MAX][MAX];
int cnt = 0;

void minMaze(int x, int y) {

    if (x == 0 && y == m - 1) {
        printf("%d", cnt);
        return;
    }

    route[x][y] = 1;
    cnt++;

    //상
    if (x - 1 >= 0 && maze[x - 1][y] != 1 && route[x - 1][y] == 0) minMaze(x - 1, y);
    //우
    if (y + 1 < m && maze[x][y + 1] != 1 && route[x][y + 1] == 0) minMaze(x, y + 1);
    //하
    if (x + 1 < n && maze[x + 1][y] != 1 && route[x + 1][y] == 0) minMaze(x + 1, y);
    //좌
    if (y - 1 >= 0 && maze[x][y - 1] != 1 && route[x][y - 1] == 0) minMaze(x, y - 1);

}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    minMaze(n - 1, 0);
    return 0;
}