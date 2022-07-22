//
// Created by 김승헌 on 2022/07/22.
//
#include <cstdio>
#include <stack>
#include <string.h>

const int MAX = 50;

using namespace std;

stack<int> myStack;
char paren[MAX];
int len;

int main() {

    scanf("%s", paren);

    len = strlen(paren);

    for (int i = 0; i < len; i++) {

        if (paren[i] == '(') {
            myStack.push(i);
        } else {//')'인 경우

            if (myStack.empty()) { // 다짝짓고 ) 남았는데 myStack에 ( 는 안남아있는 경우
                printf("NO\n");
                return 0;
            } else { // 정상적으로 짝이 이루어지는 경우 myStack에 있던 ( 위에서부터 pop
                myStack.pop();
            }

        }
    }

    // 다 짝지어지고 나서도 ( 가 myStack 에 남아있는 경우
    if (!myStack.empty()) printf("NO\n");
    else printf("YES\n");

    return 0;
}