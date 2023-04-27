#include <cstdio>

long long int N, R, P;

int main() {
	scanf("%lld %lld %lld", &N, &R, &P);

	long long int* memo = new long long int[N + 3];
	memo[0] = 0;
	memo[1] = 0;
	memo[2] = R + P;

	for (int i = 3; i <= N; i++) {
		long long int cand1 = memo[i - 1] + P;		// if just added print
		long long int cand2 = memo[(i + 1) / 2] + P + R;
		long long int cand3 = memo[(i + 2) / 3] + (2 * P) + R;
		long long int cand4 = memo[(i + 6) / 7] + (6 * P) + R;

//		printf("cand[%d]: %lld %lld %lld %lld ", i, cand1, cand2, cand3, cand4);
		memo[i] = cand1 < cand2 ? cand1 : cand2;
		memo[i] = cand3 < memo[i] ? cand3 : memo[i];
		if (memo[i] == cand1) {
//			printf("1\n");
		} else if (memo[i] == cand2){
//			printf("2\n");
		} else if (memo[i] == cand3) {
//			printf("3\n");
		} else {
			printf("%d 5\n", i);
		}
	}

//	for (int i = 0; i <= N; i++) {
//		printf("memo[%d]: %lld\n", i, memo[i]);
//	}

	printf("%lld\n", memo[N]);
	return 0;
}
