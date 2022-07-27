//
// Created by 김승헌 on 2022/07/27.
//
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100;

int n, m;
int result;

struct edge {
    int p;//시작점
    int q;//끝점
    int cost;//가중치
};//하나의 간선 정보를 받는 변수

vector<edge> edgeList; // 엣지형 타입의 변수를 여러개 받는 변수
int parent[MAX]; // parent[x] : x 의 부모노드의 번호

edge makeEdge(int a, int b, int c) { // 엣지형 타입 값들을 함수 처리해서 깔끔하게 정리
    edge temp;

    temp.p = a;
    temp.q = b;
    temp.cost = c;

    return temp;
}

bool compare(edge e1, edge e2) { // 간선 가중치들만 비교
    if (e1.cost < e2.cost) return true; // e1 < e2 이면 true 반환
    else return false; // e1 > e2 이면 false 반환
}

int find(int x) {
    //내 자신이 루트노드인지를 먼저 판단
    if (x == parent[x]) return x; // 내가 대표라면 나를 반환
    else {
        int y = find(parent[x]); // 내 부모의 root == 내 root
        parent[x] = y; // x의 부모를 y로 만들어주자(root로 만들기)
        return y; // root 반환
    }
}

bool Union(int a, int b) {

    int rootA = find(a); // a가 속한 트리의 root 찾기
    int rootB = find(b); // a가 속한 트리의 root 찾기

    // a 와 b 가 같은 그룹인지를 판단
    if (rootA == rootB) return false; // 같은 그룹이라면 false
    else { // 다른 그룹이라면
        parent[rootA] = rootB; // a와 b 를 같은 그룹으로 만들기
        return true; // true 반환
    }
}

int main() {

    // 1. 그래프 입력을 받는다
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) parent[i] = i; // 내자신이 부모노드이다

    for (int i = 0; i < m; ++i) {
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        edgeList.push_back(makeEdge(a, b, c));
    }

    // 2. 간선 가중치가 작은 순서대로 정렬을 한다(오름차순 정렬)
    // 정수형이라면 상관없지만 edge 형 이기때문에 우리가 비교하는 함수(compare)를 만들어주자
    sort(edgeList.begin(), edgeList.end(), compare);

    for (int i = 0; i < m; ++i) {
        // 3. 간선 가중치가 작은 간선부터 차례대로 선택하려는 시도를 해본다

        // 3-1. 만약 시작점과 끝점이 다른 그룹에 속한다면(Union == true)
        // 해당 간선의 가중치를 result 에 더해준다
        if (Union(edgeList[i].p, edgeList[i].q)) result += edgeList[i].cost;
    }
    printf("%d\n", result); // 15

    return 0;
}