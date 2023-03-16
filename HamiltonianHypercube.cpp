#include <cstdio>

long toDecimal(char* C, int N) {
	bool rev = false;
	long result = 0;
	long one = 1;

	for (int i = 0; i < N; i++) {
		int val = C[i] - '0';

		if (val != rev) {		// reverse, 0 or not reverse, 1
			result += one << (N - i - 1);
		}
		if (C[i] == '1') {
			rev = !rev;
		}
	}

	return result;
}

int main() {
	int N;
	scanf("%d", &N);

	char* A = new char[N + 1];
	char* B = new char[N + 1];

	scanf("%s %s", A, B);

	long diff = toDecimal(A, N) - toDecimal(B, N);
	if (diff < 0) {
		diff *= -1;
	}
	diff--;

	printf("%ld\n", diff);
	return 0;
}
