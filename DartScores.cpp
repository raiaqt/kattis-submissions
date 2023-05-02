#include <cstdio>

int R[12];
int P[12] = {10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

int getPoints(int x, int y) {
	int C = (x * x) + (y * y);

	int i = 0;
	while (C > R[i]) {
		i++;
	}

	return P[i];
}

int main() {
	for (int i = 0; i < 11; i++) {
		R[i] = (i * 20) * (i * 20);
	}

	R[11] = 100000;

	int T;
	scanf("%d", &T);

	int N, x, y;

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);

		int sum = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &x, &y);

			sum = getPoints(x, y);
		}

		printf("%d\n", sum);
	}


    return 0;
}
