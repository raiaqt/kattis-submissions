#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);

	int grade[1005];

	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);

		int total = 0;

		for (int i = 0; i < N; i++) {
			scanf("%d", &grade[i]);
			total += grade[i];
		}

		int above = 0;

		for (int i = 0; i < N; i++) {
			if (grade[i] * N > total) {
				above++;
			}
		}

		double percent = ((double) above / (double) N) * 100;

		printf("%.3f%%\n", percent);
	}
	return 0;
}
