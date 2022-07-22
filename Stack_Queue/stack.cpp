//
// Created by 김승헌 on 2022/07/22.
//
#include <cstdio>

const int MAX = 100;

int n, m;
int menu, value;
int myStack[MAX];
int capacity;
int myTop = 0;

struct stack {

    void create(int x) {
        capacity = x;
    }

    void push(int x) {

        if (myTop >= capacity) printf("Overflow\n");
        else {
            myStack[myTop] = x;
            myTop++;
        }
    }

    void pop() {

        if (myTop <= 0) printf("Underflow\n");
        else {
            myStack[myTop - 1] = 0;
            myTop--;
        }
    }

    void top() {

        if (myTop <= 0 && myStack[myTop - 1] == 0) printf("NULL\n");
        else {
            printf("%d\n", myStack[myTop - 1]);
        }
    }
} s;

int main() {

    scanf("%d %d", &n, &m);

    s.create(n);

    for (int i = 0; i < m; i++) {
        scanf("%d", &menu);

        if (menu == 1) {
            scanf("%d", &value);
            s.push(value);
        } else if (menu == 2) {
            s.pop();
        } else {
            s.top();
        }
    }

    return 0;
}