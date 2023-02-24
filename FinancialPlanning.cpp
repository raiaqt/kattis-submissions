#include <cstdio>

const int num = 100005;
long cost[num];
long profit[num];
int N, M;

bool solve(long days) {
    long total = 0;
    for (int i = 0; i < N; i++) {
        long cand = (profit[i] * days) - cost[i];
        if (cand > 0) {
            total += cand;
        }
        if (total >= M) {
            return true;
        }
    }

    return total >= M;
}

int main() {
    N = 0;
    M = 0;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &profit[i], &cost[i]);
    }

    long max = 20000000000;
    int min = 1;

    while (max - min > 1) {
        int mid = (max + min) / 2;
        bool result = solve(mid);

        if (result) {
            max = mid;
        }
        else {
            min = mid;
        }
    }
    printf("%d\n", solve(min) ? min : max);

    return 0;
}