#include <cstdio>
#include <iostream>

int main() {
    const int maxin = 1000000;
    int N, first;
    int *B = new int[maxin];
    int size = 0;
    scanf("%d", &N);
    scanf("%d", &first);

    int curr = first;
    for (int i = 1; i < N; i++) {
        int num;
        scanf("%d", &num);
        if (num > curr) {
            B[size] = num;
            curr = num;
            size++;
        }
    }

    printf("%d\n", size + 1);
    printf("%d", first);
    for (int i = 0; i < size; i++) {
        printf(" %d", B[i]);
    }

    return 0;
}