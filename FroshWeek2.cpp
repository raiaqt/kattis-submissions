#include <cstdio>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int* taskCount = new int[100005]{0};
    int* quietCount = new int[100005]{0};
    
    int t;
    for (int i = 0; i < N; i++) {
        scanf("%d", &t);
        taskCount[t - 100000]++;
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &t);
        quietCount[t - 100000]++;
    }

    int tasks = 0;
    int done = 0;
    
    for (int i = 0; i < 100005; i++) {
        tasks += taskCount[i];
        
        if (quietCount[i] > 0) {
            int doneAtTime = tasks > quietCount[i] ? quietCount[i] : tasks;
            
            done += doneAtTime;
            tasks -= doneAtTime;
        }
    }
    
    printf("%d\n", done);
    return 0;
}