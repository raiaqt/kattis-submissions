#include <cstdio>

int R, S;
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
char** seating;

int getHandshakes(int xo, int yo) {
	int total = 0;
	for (int i = 0; i < 8; i++) {
		int x = xo + dx[i];
		int y = yo + dy[i];
		if (x >= 0 && y >= 0 && x < R && y < S && seating[x][y] == 'o') {
			total++;
		}
	}
	return total;
}

int main() {
	scanf("%d %d", &R, &S);
	seating = new char*[R];

	for (int i = 0; i < R; i++) {
		seating[i] = new char[S + 1];
		scanf("%s", seating[i]);
	}

	// find Mirko's seat and his number of handshakes
	int mirko = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {
			if (seating[i][j] == '.') {
				int h = getHandshakes(i, j);
				if (h > mirko)
					mirko = h;
			}
		}
	}

	// find total number of handshakes without Mirko
	int noMirko = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {
			if (seating[i][j] == 'o') {
				noMirko += getHandshakes(i, j);
			}
		}
	}

	int total = mirko + (noMirko / 2);
	printf("%d\n", total);

	return 0;
}
