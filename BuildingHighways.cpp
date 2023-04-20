#include <cstdio>

int main() {
    int N, A;
    scanf("%d", &N);

    int min = 2000000;
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A);
        
        if (A < min) {
            min = A;
        }
        sum += A;
    }
    
    sum += min * (N - 2l);
    
    printf("%lld", sum);

    return 0;
}