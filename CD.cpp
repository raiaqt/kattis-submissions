#include <cstdio>

int main() {
    int N, M, *A, j, i, r, n;
    scanf("%d %d", &N, &M);
    while (N + M > 0) {
        i = 0;
        A = new int[N];
        r = 0;
        for (n = 0; n < N;) scanf("%d", &A[n++]);
        while (M-- > 0) {
            scanf("%d", &j);
            while (A[i] < j && i < N) i++;
            if (A[i] == j) r++;
        }
        printf("%d\n", r);
        scanf("%d %d", &N, &M);
    }
    return 0;
}