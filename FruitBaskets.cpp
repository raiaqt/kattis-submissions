#include <cstdio>

const int MAX_WEIGHT = 200;
int N;
int* weights;
long lightBaskets;

long pow2(int n) {
	long res = 1;
	for (int i = 0; i < n; i++)
		res *= 2;
	return res;
}

void addFruit(int index, long totalWeight) {
	if (totalWeight >= MAX_WEIGHT)
		return;

	lightBaskets += totalWeight;

	for (int i = index; i < N; i++)
		addFruit(i + 1, totalWeight + weights[i]);
}

int main() {
	long fruitWeights = 0;
	long totalBaskets;
	long heavyBaskets;

	scanf("%d", &N);

	weights = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &weights[i]);
		fruitWeights += weights[i];
	}

	lightBaskets = 0;
	totalBaskets = pow2(N - 1) * fruitWeights;

	addFruit(0, 0);
	heavyBaskets = totalBaskets - lightBaskets;


	printf("%ld\n", heavyBaskets);
	return 0;
}
