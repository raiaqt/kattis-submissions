#include <cstdio>

int main() {
	int R, C;

	scanf("%d %d", &R, &C);

	char** grid = new char*[R];
	int** layout = new int*[R + 1];
	int* apples = new int[C];

	for (int i = 0; i < R; i++) {
		grid[i] = new char[C];
		scanf("%s", grid[i]);
	}

	for (int i = 0; i < R + 1; i++) {
		layout[i] = new int[C];
	}


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (grid[i][j] == 'a') {
				apples[j]++;
				grid[i][j] = '.';
			} else if (grid[i][j] == '#') {
				layout[i][j] = apples[j];
				apples[j] = 0;
			}
		}
	}

	for (int j = 0; j < C; j++) {
		layout[R][j] = apples[j];
		apples[j] = 0;
	}

	for (int i = 0; i < R + 1; i++) {
		for (int j = 0; j < C; j++) {
			if (layout[i][j] != 0) {
				for (int a = 1; a <= layout[i][j]; a++) {
					grid[i - a][j] = 'a';
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		printf("%s\n", grid[i]);
	}
	return 0;
}
