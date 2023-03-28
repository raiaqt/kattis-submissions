#include <cstdio>

int main() {
    const int max = 1000005;
    int N;
    scanf("%d", &N);
    int* count = new int[max];
    int h;
    int total = 0;
    
    for (int i = 0; i < max; i++) {
        count[i] = 0;
    }
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &h);
        count[h]++;
        total++;
    }
    
    int min = max + 1;
    int horizontal = 0;
    while (total >= 0) {
        int sum = horizontal + total;
        if (sum < min) {
            min = sum;
        }
        
        horizontal++;
        total -= count[horizontal];
    }
    
    printf("%d", min);
    
    return 0;
}