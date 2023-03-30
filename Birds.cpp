#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
    int L, D, N;
    scanf("%d %d %d", &L, &D, &N);
    
    int birds[20005];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &birds[i]);
    }
    birds[N] = 6;
    birds[N + 1] = L - 6;
    
    sort(birds, birds + N + 2);
    
    int added = 0;
    
    for (int i = 0; i < N + 2; i++) {
        int gap = birds[i + 1] - birds[i];
        int b = gap / D;
        if (b > 0) {
            if (N == 0) {
                added += b + 1;
            } else if (i == 0 || i == N) {
                added += b;
            } else {
                added += b - 1;
            }
        }
    }
    
    printf("%d\n", added);
 
    return 0;
}