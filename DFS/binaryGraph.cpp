//
// Created by 김승헌 on 2022/07/22.
//
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100005;

int n, m;
vector<int> myGraph[MAX];
int check[MAX] = {0,}; // 0: 방문안함 / 1: 방문하고 1색칠 / 2: 방문하고 2색칠
int flag = 0;

void DFS(int node, int color) {
    check[node] = color;

    for (int i = 0; i < myGraph[node].size(); i++) {

        if (check[myGraph[node][i]] == color) { // 인접한 노드 방문했는데 같은 색이면 flag = 1 로 변경, 종료
            flag = 1;
            return;
        } else flag = 0;

        if (check[myGraph[node][i]] == 0) { // 인접한 노드가 방문을 안한 상태라면 1이 아닌 색 2로 칠함/재귀
            DFS(myGraph[node][i], 3 - color);
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);

    //일단 첫번째 시작은 따로 직접 넣어주고 그 다음부터 for 문 돌려야 값이 들어감
    int node_1, node_2;

    scanf("%d %d", &node_1, &node_2);

    myGraph[node_1].push_back(node_2);
    myGraph[node_2].push_back(node_1);

    int a, b;

    for (int i = 1; i < m; i++) {
        scanf("%d %d", &a, &b);

        myGraph[a].push_back(b);
        myGraph[b].push_back(a);
    }

    //node_1 시작, color 는 1로 시작
    DFS(node_1, 1);

    if (flag == 1) printf("No");
    else printf("Yes");


    return 0;
}