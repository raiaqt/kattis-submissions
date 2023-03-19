#include <cstdio>

int main() {
	const int SPACE = 0;
	const int LOWER = 1;
	const int UPPER = 2;
	const int SYMBOL = 3;
	float count[4] = {0, 0, 0, 0};
	char line[100005];

	scanf("%s", line);

	int i = 0;
	while (line[i] != '\0') {
		char c = line[i];
		if (c == '_') {
			count[SPACE]++;
		} else if (c >= 'a' && c <= 'z') {
			count[LOWER]++;
		} else if (c >= 'A' && c <= 'Z') {
			count[UPPER]++;
		} else {
			count[SYMBOL]++;
		}
		i++;
	}

	float total = 0;
	for (int j = 0; j < 4; j++) {
		total += count[j];
	}

	for (int j = 0; j < 4; j++) {
		float ratio = count[j] / total;
		printf("%.8f\n", ratio);
	}

	return 0;
}
