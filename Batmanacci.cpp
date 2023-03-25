#include <cstdio>

int main() {
	long long int N, K;
	long long int one = 1;

	scanf("%lld %lld", &N, &K);

	int size = 90;

	long long int* fib = new long long int[size];
	fib[1] = 1;
	fib[2] = 1;
	for (int i = 3; i < size; i++) {
		fib[i] = fib[i - 2] + fib[i - 1];
	}

	K--;		// make 0 indexed
	int f = (N & one) ? 89 : 88;
	while (f > 2) {
		if (K >= fib[f - 2]) {		// focus on the right half
			K -= fib[f - 2];
			f = f - 1;
		} else {
			f = f - 2;
		}
	}

	printf("%s\n", f == 1 ? "N" : "A");

	return 0;
}
