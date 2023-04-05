#include <cstdio>

int P, C;
bool visited[100];
bool adj[100][100];
int id[100];
int low[100];
int parent[100];
int count;
bool hasBridge;

void dfs(int u) {
    visited[u] = true;
    id[u] = count++;
    low[u] = id[u];

    for (int v = 0; v < P; v++) {
    	if (adj[u][v]) {
    		if (!visited[v]) {
        		parent[v] = u;
        		dfs(v);

        		if (id[u] < low[v]) {
        			hasBridge = true;
        		}
    		}
        	if (parent[u] != v) {
        		if (low[v] < low[u]) {
        			low[u] = low[v];
        		}
        	}
    	}
    }
}

int main() {
    scanf("%d %d", &P, &C);

    while (P + C > 0) {
        for (int i = 0; i < P; i++) {
            visited[i] = false;
            low[i] = -1;
            id[i] = -1;
            parent[i] = -1;

            for (int j = 0; j < P; j++) {
                adj[i][j] = false;
            }
        }
        count = 0;
        hasBridge = false;
        int a, b;
        for (int i = 0; i < C; i++) {
            scanf("%d %d", &a, &b);
            adj[a][b] = true;
            adj[b][a] = true;
        }

        dfs(0);

        printf("%s\n", count < P || hasBridge ? "Yes" : "No");
        scanf("%d %d", &P, &C);
    }
    return 0;
}
