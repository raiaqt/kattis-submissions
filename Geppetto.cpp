#include <cstdio>

int N, M;
int* banned;

bool isValid(int c) {
	for (int i = 0; i < M; i++) {
		if ((c & banned[i]) == banned[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d %d", &N, &M);

	banned = new int[M];

	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);

		int bit = 0;
		bit += 1 << (a - 1);
		bit += 1 << (b - 1);
		banned[i] = bit;
	}

	int C = 1 << N;
	int total = C;

	for (int i = 0; i < C; i++) {
		if (!isValid(i)) {
			total -= 1;
		}
	}

	printf("%d\n", total);
    return 0;
}
