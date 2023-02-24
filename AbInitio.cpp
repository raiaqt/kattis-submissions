#include <cstdio>

// Vertices are 0 indexed
int vMax = 4000;
int V;		// [2, 2000]
int E;		// [1, 200000]
int Q;		// [1, 2000]
int r = 1000000007;

int main() {
	scanf("%d %d %d", &V, &E, &Q);
	bool matrix[vMax][vMax];
	bool transpose = false;
	bool complement = false;

	for (int i = 0; i < E; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		matrix[A][B] = true;
	}

	for (int i = 0; i < Q; i++) {
		int q;
		scanf("%d", &q);

		if (q == 1) {
			for (int j = 0; j < V; j++) {
				matrix[V][j] = complement;
				matrix[j][V] = complement;
			}
			V++;
		} else if (q == 2) {
			// add and edge from X->Y or Y->X
			int X, Y;
			scanf("%d %d", &X, &Y);
			if (transpose) {
				matrix[Y][X] = !complement;
			} else {
				matrix[X][Y] = !complement;
			}
		} else if (q == 3) {
			// delete all edges involving X
			int X;
			scanf("%d", &X);

			for (int j = 0; j < V; j++) {
				matrix[X][j] = complement;
				matrix[j][X] = complement;
			}
		} else if (q == 4) {
			// remove edge X->Y or Y->X
			int X, Y;
			scanf("%d %d", &X, &Y);
			if (transpose) {
				matrix[Y][X] = complement;
			} else {
				matrix[X][Y] = complement;
			}
		} else if (q == 5) {
			transpose = !transpose;
		} else if (q == 6) {
			complement = !complement;
		}
	}

	printf("%d\n", V);

	for (int i = 0; i < V; i++) {
		int sum = 0;
		long hash = 0;
		long mult = 1;
		for (int j = 0; j < V; j++) {
			bool edge = transpose ? matrix[j][i] : matrix[i][j];
			if (i != j) {
				if ((complement && !edge) || (!complement && edge)) {
					sum++;
					long addToHash = (mult * j) % r;
					hash = (hash + addToHash) % r;
					mult = (mult * 7) % r;
				}
			}
		}

		printf("%d %d\n", sum, hash);
	}

	return 0;
}
