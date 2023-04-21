#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);

    int height = 0;
    int side = 1;
    while (N > 0) {
        N -= (side * side);

        if (N >= 0) {
            height++;
            side += 2;
        }
    }

    printf("%d\n", height);
    return 0;
}
