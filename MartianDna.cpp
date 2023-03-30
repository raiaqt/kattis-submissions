#include <cstdio>

int* dna;
int* req;
int* totalReq;

int main() {
	int N, K, R;
    scanf("%d %d %d", &N, &K, &R);

    dna = new int[N];
    req = new int[K];
    totalReq = 0;

    for (int i = 0; i < N; i++) {
    	scanf("%d", &dna[i]);
    }

    for (int i = 0; i < R; i++) {
    	int B, Q;
    	scanf("%d %d", &B, &Q);
    	req[B] = Q;
    	totalReq += Q;
    }

    int min = N + 100;
    int j = 0;
    for (int i = 0; i < N; i++) {
    	int addBase = dna[i];
		req[addBase]--;
    	if (req[addBase] >= 0) {
    		totalReq--;
    	}

    	while (true) {
        	int removeBase = dna[j];
        	// if base is in excess
        	if (req[removeBase] < 0) {
        		req[removeBase]++;
        		j++;
        	} else {
        		break;
        	}
    	}

    	if (totalReq == 0) {
    		if (i - j + 1 < min) {
    			min = i - j + 1;
    		}
    	}
    }

    if (min == N + 100) {
    	printf("impossible\n");
    } else {
    	printf("%d\n", min);
    }
    return 0;
}
