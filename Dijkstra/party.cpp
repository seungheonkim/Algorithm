//
// Created by 김승헌 on 2022/07/25.
//
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100010;

vector<int> graph[MAX];
vector<int> cost[MAX];

int Table[MAX];
bool check[MAX];

vector<int> reverseGraph[MAX];
vector<int> reverseCost[MAX];

int reverseTable[MAX];
bool reverseCheck[MAX];

int n, m, k;
int a, b, c;

void inNode(int node) {
    for (int i = 0; i <= n; ++i) {
        Table[i] = 999999999;
        check[i] = 0;
    }
    Table[node] = 0;
}


void dijkstra() {
    for (int i = 0; i <= n; ++i) {
        int minVale = 999999999, minIndex = -1;
        for (int j = 0; j <= n; ++j) {
            if (!check[j] && minVale > Table[j]) {
                minVale = Table[j];
                minIndex = j;
            }
        }
        check[minIndex] = true;

        for (int j = 0; j < graph[minIndex].size(); ++j) {
            int next = graph[minIndex][j];
            int next_cost = cost[minIndex][j];

            if (Table[next] > Table[minIndex] + next_cost) {
                Table[next] = Table[minIndex] + next_cost;
            }
        }
    }
}

void reverseInNode(int node) {
    for (int i = 0; i <= n; ++i) {
        reverseTable[i] = 999999999;
        reverseCheck[i] = 0;
    }
    reverseTable[node] = 0;
}

void reversedijkstra() {
    for (int i = 0; i <= n; ++i) {
        int minVale = 999999999, minIndex = -1;
        for (int j = 0; j <= n; ++j) {
            if (!reverseCheck[j] && minVale > reverseTable[j]) {
                minVale = reverseTable[j];
                minIndex = j;
            }
        }
        reverseCheck[minIndex] = true;

        for (int j = 0; j < reverseGraph[minIndex].size(); ++j) {
            int next = reverseGraph[minIndex][j];
            int next_cost = reverseCost[minIndex][j];

            if (reverseTable[next] > reverseTable[minIndex] + next_cost) {
                reverseTable[next] = reverseTable[minIndex] + next_cost;
            }
        }
    }
}

int main() {

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);

        graph[a].push_back(b);
        cost[a].push_back(c);

        reverseGraph[b].push_back(a);
        reverseCost[b].push_back(c);
    }

    inNode(k);
    dijkstra();

    //각자집  -> 철수집 갈때
    int sum = 0;

    for (int i = 1; i <= n; ++i) {
        sum += Table[i];
    }

    // 철수집 -> 각자집 돌아갈때
    reverseInNode(k);
    reversedijkstra();

    for (int i = 1; i <= n; ++i) {
        sum += reverseTable[i];
    }

    printf("%d", sum);

    return 0;
}