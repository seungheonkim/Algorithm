//
// Created by 김승헌 on 2022/07/22.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX = 25;

int house[MAX][MAX];
int visited[MAX][MAX] = {0,};
vector<int> houseNum;

//상 우 하 좌
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, 1, 0, -1};
int n;
int cnt;

void DFS(int x, int y) {

    for (int i = 0; i < 4; i++) {

        int rx = x + dir_x[i];
        int ry = y + dir_y[i];

        if (rx >= n || rx < 0 || ry >= n || ry < 0) continue;

        if (visited[rx][ry] == 0 && house[rx][ry] == 1) {   //방문 안했고 집이 있으면
            visited[rx][ry] = 1;                    //방문했다고 표시하고
            cnt++;                                 //집 개수 세기
            DFS(rx, ry);
        }
    }

}


int main() {

    int group = 0;

    scanf("%d", &n);

    char string[MAX][MAX];

    for (int i = 0; i < n; ++i) {
        scanf("%s", string[i]);
        for (int j = 0; j < strlen(string[i]); ++j) {

            if (string[i][j] == '1') {
                house[i][j] = 1;
            } else house[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            if (house[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = 1;
                cnt = 1;                        //처음은 시작점 포함하므로 1로 초기화
                DFS(i, j);
                houseNum.push_back(cnt);
                group++;                          //단지 그룹 1개 탐색 끝남
            }
        }
    }

    sort(houseNum.begin(), houseNum.end());

    printf("%d\n", group);

    for (int i = 0; i < houseNum.size(); ++i) {
        printf("%d\n", houseNum[i]);
    }

    return 0;
}