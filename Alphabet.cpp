#include <cstdio>

int main() {
    char alphabet[55];
    int memo[55];

    scanf("%s", alphabet);

    for (int i = 0; i < 55; i++) {
        memo[i] = 0;
    }

    int i = 0;
    int longest = 0;
    while (alphabet[i] != '\0') {
        int max = 0;

        for (int j = 0; j < i; j++) {
        	if (alphabet[j] < alphabet[i] && memo[j] > max) {
        		max = memo[j];
        	}
        }

        memo[i] = max + 1;

        if (memo[i] > longest) {
            longest = memo[i];
        }

        i++;
    }

    printf("%d\n", 26 - longest);

    return 0;
}
