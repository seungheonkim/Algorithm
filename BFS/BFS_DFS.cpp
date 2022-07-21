//
// Created by 김승헌 on 2022/07/20.
//
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1100;

int n, m;
vector<int> myGraph[MAX];
bool check_DFS[MAX] = {0,};
bool check_BFS[MAX] = {0,};

void DFS(int x) {

    check_DFS[x] = true;

    printf("%d ", x);

    for (int i = 0; i < myGraph[x].size(); i++) {
        int next = myGraph[x][i];

        if (check_DFS[next] == false) {
            DFS(next);
        }
    }
}

void BFS() {
    queue<int> Queue;

    Queue.push(0);
    check_BFS[0] = true;

    while (!Queue.empty()) {
        int current = Queue.front();
        Queue.pop();

        printf("%d ", current);

        for (int i = 0; i < myGraph[current].size(); i++) {
            int next = myGraph[current][i];

            if (check_BFS[next] == false) {
                check_BFS[next] = true;
                Queue.push(next);
            }
        }
    }

}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;

        scanf("%d %d", &a, &b);

        myGraph[a].push_back(b);
        myGraph[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        sort(myGraph[i].begin(), myGraph[i].end());
    }

    DFS(0);
    printf("\n");
    BFS();

    return 0;
}

