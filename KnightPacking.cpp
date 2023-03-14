#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    
    printf("%s", N & 1 ? "first" : "second");
    
    return 0;
}