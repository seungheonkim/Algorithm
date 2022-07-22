//
// Created by 김승헌 on 2022/07/22.
//
#include <cstdio>

const int MAX = 100;

int n, m;
int menu, value;
int front, rear;
int myQueue[MAX];
int capacity;
int numElement;

struct circleQueue {

    void create(int x) {
        capacity = x;
        front = 0;
        rear = 0;
        numElement = 0;
    }

    void push(int x) {

        if (numElement >= capacity) printf("Overflow\n");
        else {
            myQueue[rear] = x;
            rear++;
            numElement++;

            if (rear >= MAX) rear = 0;
        }
    }

    void pop() {

        if (numElement <= 0) printf("Underflow\n");
        else {
            myQueue[front] = 0;
            front++;
            numElement--;

            if (front >= MAX) front = 0;
        }
    }

    void first() {

        if(numElement <= 0 && myQueue[front] == 0) printf("NULL\n");
        else{
            printf("%d\n", myQueue[front]);
        }
    }

} cq;


int main() {

    scanf("%d %d", &n, &m);

    cq.create(n);

    for (int i = 0; i < m; i++) {
        scanf("%d", &menu);
        if (menu == 1) {
            scanf("%d", &value);
            cq.push(value);
        } else if (menu == 2) {
            cq.pop();
        } else cq.first();
    }


    return 0;
}