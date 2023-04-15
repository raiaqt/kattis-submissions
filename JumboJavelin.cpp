#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);

	int length = 0;

	for (int i = 0; i < N; i++) {
		int rod;
		scanf("%d", &rod);
		length += rod;
	}

	printf("%d\n", length - N + 1);
    return 0;
}
