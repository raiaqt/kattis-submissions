#include <cstdio>

long long int N, R, P;

int main() {
	scanf("%lld %lld %lld", &N, &R, &P);

	long long int* memo = new long long int[N + 3];
	memo[0] = 0;
	memo[1] = 0;
	memo[2] = R + P;

	for (int i = 3; i <= N; i++) {
		int cand1 = memo[i - 1] + P;		// if just added print
		int cand2 = memo[(i + 1) / 2] + P + R;

		printf("cand[%d]: %d %d\n", i, cand1, cand2);
		memo[i] = cand1 < cand2 ? cand1 : cand2;
	}

	for (int i = 0; i <= N; i++) {
		printf("memo[%d]: %d\n", i, memo[i]);
	}

	printf("%lld\n", memo[N]);
	return 0;
}
