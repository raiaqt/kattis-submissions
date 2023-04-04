#include <cstdio>

int P, C;
bool visited[100];
bool adj[100][100];
int id[100];
int low[100];
int count;

void dfs(int curr, int parent) {
    visited[curr] = true;
    id[curr] = count++;
    low[curr] = 2 * P;
    for (int i = 0; i < P; i++) {
        if (adj[curr][i]) {
            if (!visited[i]) {
                dfs(i, curr);
                low[curr] = low[i] < low[curr] ? low[i] : low[curr];
            } else if (i != parent) {   // has back edge
               low[curr] = id[i] < low[curr] ? id[i] : low[curr];
            }
        }
    }
}

bool hasBridge() {
    bool result = false;
    for (int i = 1; i < P; i++) {
        if (low[i] == 2 * P) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &P, &C);

    while (P + C > 0) {
        // if (P == 1 && C == 0) {
        //     printf("No\n");
        //     scanf("%d %d", &P, &C);
        //     continue;
        // }
        for (int i = 0; i < P; i++) {
            visited[i] = false;
            low[i] = -1;
            id[i] = -1;
            
            for (int j = 0; j < P; j++) {
                adj[i][j] = false;
            }
        }
        count = 0;
        int a, b;
        for (int i = 0; i < C; i++) {
            scanf("%d %d", &a, &b);
            adj[a][b] = true;
            adj[b][a] = true;
        }
        
        dfs(0, -1);
        
        printf("%s\n", count < P || hasBridge() ? "Yes" : "No");
        scanf("%d %d", &P, &C);
    }
    return 0;
}