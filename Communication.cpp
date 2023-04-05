#include <cstdio>

bool isOne(int num, int i) {
	return (num & (1 << i)) != 0;
}

int main() {
    int N, B;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
    	scanf("%d", &B);

    	int result = 0;
    	bool curr = false;

    	for (int i = 0; i < 8; i++) {
    		if (isOne(B, i) != curr) {
    			result += 1 << i;
    			curr = true;
    		} else {
    			curr = false;
    		}
    	}

    	if (i > 0) {
    		printf(" ");
    	}

    	printf("%d", result);
    }
	printf("\n");
    return 0;
}
