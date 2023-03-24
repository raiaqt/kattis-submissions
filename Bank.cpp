#include <cstdio>

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    
    const int max = 10005;
    int c[max];
    int t[max];
    bool done[max];
    int result = 0;
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &c[i], &t[i]);
        done[i] = false;
    }
    
    for (int i = T - 1; i >= 0; i--) {
        // find max among those who haven't left
        int timeMax = 0;
        int timeMaxIndex = 0;
        for (int j = 0; j < N; j++) {
            if (!done[j] && t[j] >= i && c[j] > timeMax) {
                timeMax = c[j];
                timeMaxIndex = j;
            }
        }
        if (timeMax > 0) {
            result += timeMax;
            done[timeMaxIndex] = true;
        }
    }
    
    printf("%d\n", result);

    return 0;
}