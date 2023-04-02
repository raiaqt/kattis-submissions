#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);

	int* height = new int[N];

	for (int i = 0; i < N; i++) {
		scanf("%d", &height[i]);
	}

	int* lookup = new int[1000005];
	int arrows = 0;

	for (int i = 0; i < N; i++) {
		int h = height[i];
		if (lookup[h + 1] == 0) {
			lookup[h]++;
			arrows += 1;
		} else {
			lookup[h + 1]--;
			lookup[h]++;
		}
	}

	printf("%d\n", arrows);
	return 0;
}
