//
// Created by 김승헌 on 2022/07/25.
//
#include <cstdio>
#include <vector>
#include <algorithm>

const int MAX = 1000100;

using namespace std;

vector<int> graph[MAX];
//vector<int> cost[MAX]; // 간선마다 가중치가 다를 경우 대입

int n, m;
int start, final;

int Table[MAX];
bool check[MAX];

void Dijkstra(int s, int f) {
    for (int i = 0; i < n; ++i) Table[i] = 999999999;//최소값 대입시 다 들어갈수있게 충분히 큰수로 정해놓기
    Table[s] = 0;//첫번째 정점은 최단거리 0

    for (int i = 0; i < n; ++i) {
        int minValue = 999999999, minIndex = -1;//최소값 들어갈수있도록 초기값 설정

        for (int j = 0; j < n; ++j) {
            if (!check[j] && minValue > Table[j]) {//최소값이 정해지지 않은 상태 && 들어갈 최소값이 이제까지 중 제일 작을 경우
                minValue = Table[j];//해당 최소값 대입
                minIndex = j;//최소값을 가지는 minIndex 설정
            }
        }

        check[minIndex] = true;//최단거리 정보 들어갔으므로 방문 처리

        for (int j = 0; j < graph[minIndex].size(); ++j) {
            int next = graph[minIndex][j];//인접 노드 next 로 설정
//            int nextCost = cost[minIndex][j];//인접 노드의 가중치 값 설정

            if (Table[next] > Table[minIndex] + 1) {//next 노드에서의 인접노드로 가는 가중치들 중 가장 최소값 찾기
                Table[next] = Table[minIndex] + 1;//지금은 가중치가 없기에 일정한 값인 1로 설정함
            }
        }
    }

    printf("%d", Table[f]);
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {

        int a, b;

        scanf("%d %d", &a, &b);

        graph[a].push_back(b);
        graph[b].push_back(a);

//        cost[a].push_back(c); // a와 b에 간선 가중치 값인 c 대입
//        cost[b].push_back(c);
    }

    scanf("%d %d", &start, &final);

    Dijkstra(start, final);

    return 0;
}