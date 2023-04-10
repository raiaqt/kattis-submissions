#include <cstdio>

int main() {
	char letters[8];
	bool used[26];
	scanf("%s", letters);

	for (int i = 0; i < 26; i++) {
		used[i] = false;
	}

	for (int i = 0; i < 8; i++) {
		used[letters[i] - 'a'] = true;
	}

	int N;
	scanf("%d", &N);

	char word[25];
	for (int i = 0; i < N; i++) {
		scanf("%s", word);

		int w = 0;
		int same = 0;
		bool hasCenter = false;
		while (word[w] != '\0') {
			if (used[word[w] - 'a']) {
				same++;

				if (word[w] == letters[0]) {
					hasCenter = true;
				}
			}
			w++;
		}

		if (w >= 4 && w == same && hasCenter) {
			printf("%s\n", word);
		}
	}

    return 0;
}
