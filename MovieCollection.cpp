#include <cstdio>
#include <cmath>

const int maxM = 100005;
int* segtree;
int n, m, r, size;
int start;
int leaf;

int setSum(int i) {
	if (i >= n + r + 1) {
		return segtree[i];
	}
	segtree[i] = setSum(i << 1) + setSum((i << 1) + 1);
	return segtree[i];
}

int getRangeSum(int i, int j) {
	int sum = 0;
	while (i < j) {
		if (i & 1) {
			sum += segtree[i];
			i++;
		}
		if (!(j & 1)) {
			sum += segtree[j];
			j--;
		}
		i = i >> 1;
		j = j >> 1;
	}
	if (i == j) {
		sum += segtree[j];
	}
	return sum;
}

void update(int i, int diff) {
	while (i != 1) {
		segtree[i] += diff;
		i = i >> 1;
	}
}

void solve() {
	int a[maxM];
	int index[maxM];

	scanf("%d %d", &m, &r);

	for (int i = 0; i < r; i++) {
		scanf("%d", &a[i]);
	}

	leaf = m + r + 1;
	n = (1 << (int) ceil(log2(leaf)));
	size = n * 4;
	start = r + n + 1;

	segtree = new int[size];

	for (int i = 0; i < m; i++) {
		segtree[start + i] = 1;
		index[i + 1] = start + i;
	}

	// prepare the segtree
	setSum(1);

	for (int i = 0; i < r; i++) {
		int in = index[a[i]];
		int rangeSum = 0;
		if (start == in) {
			rangeSum = 0;		// empty range, start stays the same
		} else {
			rangeSum = getRangeSum(start--, in - 1);
			update(start, 1);
			update(in, -1);
			index[a[i]] = start;
		}
		printf("%d", rangeSum);
		if (i != r - 1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}

}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		solve();
	}

	return 0;
}
