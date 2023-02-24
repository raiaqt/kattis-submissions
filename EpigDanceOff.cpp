#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int N, M;
    int grid[2001];
    char input[2001];
    
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        scanf("%s", input);
        for (int j = 0; j < M; j++) {
            if (input[j] == '$') {
                grid[j]++;
            }
        }
    }
    grid[M] = 0;
    int counter = 0;
    for (int i = 0; i < M; i++) {
        if (grid[i] > 0 && grid[i + 1] == 0) {
            counter++;
        }
    }
    
    printf("%d\n", counter);
    return 0;
}