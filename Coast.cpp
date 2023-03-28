#include <cstdio>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    char** grid = new char*[N];
    for (int i = 0; i < N; i++) {
        grid[i] = new char[M + 1];
        scanf("%s", grid[i]);
    }
    
    // multi source bfs

    return 0;
}