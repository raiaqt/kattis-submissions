#include <cstdio>

using namespace std;

int main() {
    int T, N;
    char team[25];

    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d", &N);

        int* count = new int[N + 1];

        for (int i = 0; i < N; i++) {
            int a;
            scanf("%s %d", team, &a);

            count[a]++;
        }


        long badness = 0;
        int r = 1;
        for (int i = 1; i < N + 1; i++) {
            while (count[i] > 0) {
                int diff = i - r;

                if (diff < 0) {
                    diff *= -1;
                }
                badness += (diff);
                count[i]--;
                r++;
            }
        }

        printf("%ld\n", badness);
    }
    return 0;
}
