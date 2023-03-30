#include <cstdio>

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int N, M;
char* in;
char** grid;
bool** visited;
int coastLength;

bool isValid(int x, int y) {
	return x >= 0 && y >= 0 && x < N + 2 && y < M + 2;
}

void dfs(int x, int y) {
	if (visited[x][y]) {
		return;
	}

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isValid(nx, ny) && !visited[nx][ny]) {
			if (grid[nx][ny] == '0') {
				dfs(nx, ny);
			} else {
				coastLength++;
			}
		}
	}
}

int main() {
    scanf("%d %d", &N, &M);

    grid = new char*[N + 2];
    visited = new bool*[N + 2];
    in = new char[M + 1];
    coastLength = 0;

    for (int i = 0; i < N + 2; i++) {
        visited[i] = new bool[M + 2];
        grid[i] = new char[M + 2];
    }

    for (int i = 0; i < M + 2; i++) {
    	grid[0][i] = '0';
    	grid[N + 1][i] = '0';
    }

    for (int i = 1; i <= N; i++) {
        scanf("%s", in);

        grid[i][0] = '0';
        grid[i][M + 1] = '0';

        for (int j = 0; j < M; j++) {
        	grid[i][j + 1] = in[j];
        }
    }

    dfs(0, 0);

    printf("%d\n", coastLength);
    return 0;
}
