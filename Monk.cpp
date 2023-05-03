#include <cstdio>

double getSameTime(double sa1, double sa2, double ta1, double ta2, double sd1, double sd2, double td1, double td2) {
    double ma = (sa2 - sa1) / (ta2 - ta1);
    double md = (sd2 - sd1) / (td2 - td1);
    
    double n = sd1 - sa1 + (ma * ta1) + (md * td1);
    double d = ma - md;
    return n / d;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    N++;
    M++;
    int* ascendHeight = new int[N];
    int* descendHeight = new int[M];
    int* ascendTime = new int[N];
    int* descendTime = new int[M];
    
    ascendHeight[0] = 0;
    ascendTime[0] = 0;
    for (int i = 1; i < N; i++) {
        scanf("%d %d", &ascendHeight[i], &ascendTime[i]);
        ascendHeight[i] += ascendHeight[i - 1];
        ascendTime[i] += ascendTime[i - 1];
    }
    
    descendHeight[0] = ascendHeight[N - 1];
    descendTime[0] = 0;
    for (int i = 1; i < M; i++) {
        scanf("%d %d", &descendHeight[i], &descendTime[i]);
        descendHeight[i] -= descendHeight[i - 1];
        descendTime[i] += descendTime[i - 1];
    }
    
    int a = 1;
    int d = 1;
    
    int sa1 = 0;
    int sd1 = descendHeight[0];
    int ta1 = 0;
    int td1 = 0;
    
    while (a < N && d < M) {
        double sameTime = getSameTime(sa1, ascendHeight[a], ta1, ascendTime[a],
                                    sd1, descendHeight[d], td1, descendTime[d]);
        sa1 = ascendHeight[a];
        sd1 = descendHeight[d];
        ta1 = ascendTime[a];
        td1 = descendTime[d];
        
        if (ta1 > td1) {
            d++;
        } else {
            a++;
        }
        printf("%lf\n", sameTime);
    }
    return 0;
}