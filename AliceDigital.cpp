
#include <cstdio>

int main() {
	const int maxN = 100005;
	int T;
	scanf("%d", &T);

	int arr[maxN];
	int sum[maxN];
	int mIndex[maxN];

	for (int t = 0; t < T; t++) {
		int N, M;
		scanf("%d %d", &N, &M);

		int mCount = 0;

		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] == M) {
				mIndex[mCount++] = i;
			}
		}

		// prepare prefix sums
		sum[0] = 0;
		for (int i = 0; i < N; i++) {
			sum[i + 1] = sum[i] + arr[i];
		}

		int maxWeight = 0;

        // for every occurence of m,
        // find the start and end index of maximum subarray length containing m
		for (int i = 0; i < mCount; i++) {
			int start = mIndex[i] - 1;
			int end = mIndex[i] + 1;

			while (arr[start] > M && start >= 0) { start--; }
			while (arr[end] > M && end < N) { end++; }

			int weight = sum[end] - sum[start + 1];

			if (weight > maxWeight) {
				maxWeight = weight;
			}
		}

		printf("%d\n", maxWeight);
	}

	return 0;
}
