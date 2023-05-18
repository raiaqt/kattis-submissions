#include <cstdio>

int N;
char colors[12][25];
bool hideous[12][12];
int result[12];
int temp[12];
bool visited[12];
int valid;
bool found;

bool isEqual(char a[25], char b[25]) {
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return false;
        }
        i++;
	}
    if (a[i] != b[i]) {
    	return false;
    }
    return true;
}

int getIndex(char c[25]) {
    for (int i = 0; i < N; i++) {
        if (isEqual(c, colors[i])) {
            return i;
        }
    }
    return -1;
}

void search(int resIndex, int c) {
//	visited[c] = true;
	temp[resIndex] = c;

	if (resIndex == N - 1) {
		if (!found) {
			for (int i = 0; i < N; i++) {
				result[i] = temp[i];
			}
			found = true;
		}
//		for (int i = 0; i < N; i++) {
//			printf("%s ", colors[temp[i]]);
//		}
//		printf("\n");
		valid++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i] && !hideous[c][i]) {
			visited[i] = true;
			search(resIndex + 1, i);
			visited[i] = false;
		}
	}

//	visited[c] = false;
}

int main() {
    int T;
    scanf("%d", &T);

    char a[25];
    char b[25];

    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%s", colors[i]);
        }

        // clear up matrix, initialize visited
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                hideous[i][j] = false;
            }
            visited[i] = false;
        }
        valid = 0;
        found = false;

        int M;
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
            scanf("%s %s", a, b);
            int aIndex = getIndex(a);
            int bIndex = getIndex(b);

            hideous[aIndex][bIndex] = true;     // a and b cannot be adjacent
            hideous[bIndex][aIndex] = true;
        }

        for (int i = 0; i < N; i++) {
        	visited[i] = true;
        	search(0, i);
        	visited[i] = false;
        }

        printf("%d\n", valid);

        for (int i = 0; i < N; i++) {
        	if (i != 0) {
        		printf(" ");
        	}
        	printf("%s", colors[result[i]]);
        }
        printf("\n");

    }

    return 0;
}
