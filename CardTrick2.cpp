#include <cstdio>

int N;
int result[15];

void print() {
    for (int i = 0; i < N; i++) {
        if (i > 0){
            printf(" ");
        }
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    int T;

    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            result[i] = -1;
        }

        int num = 1;
        int curr = -1;
        while (num <= N) {
            int move = 0;
            while (move <= num) {
                curr = (curr + 1) % N;
                if (result[curr] == -1) {
                    move++;
                }
            }
            result[curr] = num++;
        }

        print();
    }
    return 0;
}