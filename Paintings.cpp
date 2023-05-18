#include <cstdio>

int N;
char colors[12][25];
bool hideous[12][12];

bool isEqual(char a[25], char b[25]) {
    for (int i = 0; i < 25; i++) {
        if (a[i] != b[i]) {
            return false;
        }
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
        
        // clear up matrix
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                hideous[i][j] = false;
            }
        }
        
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
            for (int j = 0; j < N; j++) {
                printf("%d ", hideous[i][j]);
            }
            printf("\n");
        }
    }
    printf("done\n");

    return 0;
}