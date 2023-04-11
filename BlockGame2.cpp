#include <cstdio>

int main() {
    long long unsigned int N, M;
    scanf("%llu %llu", &N, &M);

    if (N < M) {
        long long unsigned int t = N;
        N = M;
        M = t;
    }
    bool move = false;
    while (N > 0 && M > 0) {
        long long unsigned int mod = N % M;
        if (mod == 0 || N > mod + M) {
            move = !move;
            break;
        }  
        N = M;
        M = mod;
        move = !move;
    }

    printf("%s\n", move ? "win" : "lose");

    return 0;
} 
