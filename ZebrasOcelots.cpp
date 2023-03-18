#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    long long int zo = 0;
    char animal[2];
    for (int i = 0; i < N; i++) {
        scanf("%s", animal);
        if (animal[0] == 'O') {
            zo = zo | 1L << (N - i - 1);
        }
    }
    
    printf("%lld\n", zo);
    
    return 0;
}