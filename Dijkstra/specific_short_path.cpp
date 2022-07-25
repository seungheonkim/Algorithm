//
// Created by 김승헌 on 2022/07/25.
//
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100010;

vector<int> graph[MAX];
vector<int> cost[MAX];

int Table[MAX];
bool check[MAX];

int n, m;
int a, b, c;
int A, B;
int start, final;

void initNode(int node) { // 초기화 함수
    for (int i = 0; i <= n; ++i) {
        Table[i] = 999999999;
        check[i] = 0;
    }

    Table[node] = 0;
}

void Dijkstra() {

    for (int i = 0; i <= n; ++i) {
        int minValue = 999999999, minIndex = -1;

        for (int j = 0; j <= n; ++j) {
            if (!check[j] && minValue > Table[j]) {
                minValue = Table[j];
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

int main() {

    scanf("%d %d", &n, &m);

    start = 1;
    final = n;

    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);

        graph[a].push_back(b);
        graph[b].push_back(a);

        cost[a].push_back(c);
        cost[b].push_back(c);
    }

    scanf("%d %d", &A, &B);

    //최기화 후 start 에서 최단거리 각각 구하기
    initNode(start);
    Dijkstra();

    int sum = 0;
    int flag = 0;

    //시작점 start 에서 a , b 까지 최단거리 계산
    if (Table[A] > Table[B]) {//b로 가는게 최단일때
        sum += Table[B];
        initNode(B);
        flag = 1;
    } else {//a 로 가는게 최단일때
        sum += Table[A];
        initNode(A);
    }
    Dijkstra();

    // a에서 b / b에서 a 까지의 최단거리 계산
    if (flag == 1) {
        sum += Table[A];
        initNode(A);
    } else {
        sum += Table[B];
        initNode(B);
    }
    Dijkstra();

    //해당 지점 까지의 최단거리 sum 에서 마지막 final까지 최단거리 계산
    sum += Table[final];

    printf("%d", sum);
    return 0;
}
