#include <cstdio>

int R;
int minCost;
int* dancers;
char* input;

int* out;
bool* visited;

void search(int prev, int cost, int index) {
	if (index == R) {
		if (cost < minCost) {
			minCost = cost;
		}
		return;
	}

	for (int i = 0; i < R; i++) {
		if (!visited[i]) {
			visited[i] = true;

			int next = dancers[i];
			int same = prev & next;
			int count = 0;

			// count ones
			for (int i = 0; i < 26; i++) {
				if (same & (1 << i)) {
					count++;
				}
			}

			search(next, cost + count, index + 1);
			visited[i] = false;
		}

	}

}

int main() {
	scanf("%d", &R);

	dancers = new int[R];
	input = new char[26];
	out = new int[R + 1];
	visited = new bool[R];
	minCost = R * 30;

	for (int i = 0; i < R; i++) {
		scanf("%s", input);

		int j = 0;
		dancers[i] = 0;

		while (input[j] != '\0') {
			int digit = input[j++] - 'A';

			dancers[i] += 1 << digit;
		}
	}

	search(0, 0, 0);

	printf("%d", minCost);

    return 0;
}
