//
// Created by 김승헌 on 2022/07/20.
//

#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 100010;

int n;
queue<pair<int, int>> q;
bool check[MAX];

void weirdCalc(int num, int cnt) {
    pair<int, int> tmp = make_pair(num, cnt);
    q.push(tmp);
    check[num] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        if (current.first == n) {
            printf("%d", current.second);
            return;
        }

        int num1, num2;
        num1 = current.first * 2;
        num2 = current.first / 3;

        if (num1 < 100000 && check[num1] == false) {
            check[num1] = true;
            tmp.first = num1;
            tmp.second = current.second + 1;
            q.push(tmp);
        }

        if (num2 < 100000 && check[num2] == false && num2 != 0) {
            check[num2] = true;
            tmp.first = num2;
            tmp.second = current.second + 1;
            q.push(tmp);
        }
    }
    return;
}

int main() {

    scanf("%d", &n);

    weirdCalc(1, 0);

    return 0;
}