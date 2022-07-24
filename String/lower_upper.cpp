//
// Created by 김승헌 on 2022/07/24.
//
#include <cstdio>
#include <cstring>

    char arr[1005];

int main() {
    fgets(arr, 1005, stdin);

    scanf("%s ", arr);

    int lenarr = strlen(arr);

    for (int i = 0; i < lenarr; i++) {

        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            printf("%c", arr[i] - 'A' + 'a');
        } else if (arr[i] >= 'a' && arr[i] <= 'z') {
            printf("%c", arr[i] - 'a' + 'A');
        } else printf("%c", arr[i]);
    }
    return 0;
}