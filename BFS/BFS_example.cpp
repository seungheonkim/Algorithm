//
// Created by 김승헌 on 2022/07/20.
//
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100;

int n, m;
vector<int> myGraph[MAX];

void BFS() {

    bool check[MAX] = {0,}; // check[x] = true 이면 x 가 색칠됨
//    1. 시작점을 큐에 삽입
    queue<int> Queue;

//    Queue.push(x); // x를 큐에 삽입
//    Queue.pop(); // 큐 맨앞에 있는 원소를 제거
//    Queue.front(); // 맨 앞에 있는 원소를 반환
//    Queue.empty(); //비어있으면 true 반환

//    2. 시작점을 색칠
    Queue.push(1);
    check[1] = true;

//    3. BFS 시작
    while (!Queue.empty()) { // 큐가 비어있을때까지 계속 실행!!
//    4. 큐에서 하나를 pop (현재 위치)
        int current = Queue.front();
        Queue.pop();

        printf("%d ", current);

//    5. 인접한 모든 정점에게 방문했는지 물어보고
//        방문하지 않았다면 색칠하고 큐에 삽입
        for (int i = 0; i < myGraph[current].size(); i++) {
            int next = myGraph[current][i];

            if (check[next] == false) {
                check[next] = true;
                Queue.push(next);
            }
        }
//    6. 모두 완료했다면 다시 3번으로 돌아감
    }
}

//9 12
//1 2
//1 3
//2 3
//2 4
//2 6
//3 7
//4 5
//4 7
//4 8
//5 6
//7 8
//8 9

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int a, b;

        scanf("%d %d", &a, &b);

        myGraph[a].push_back(b);
        myGraph[b].push_back(a);

    }

    BFS();

    return 0;
}
