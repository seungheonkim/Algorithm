//
// Created by 김승헌 on 2022/07/22.
//
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 105;

int n, m;
vector<int> myCom[MAX];
bool check[MAX];
int cnt = 0;

void DFS(int x) {
    check[x] = true;

    if (x == 1) cnt = 0;
    else cnt++;

    for (int i = 0; i < myCom[x].size(); ++i) {
        int next = myCom[x][i];

        if (check[next] == false) DFS(next);
    }
}

int main() {

    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
        int a, b;

        scanf("%d %d", &a, &b);

        myCom[a].push_back(b);
        myCom[b].push_back(a);
    }

    DFS(1);

    printf("%d", cnt);

    return 0;
}
