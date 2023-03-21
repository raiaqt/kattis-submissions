#include <cstdio>

double factorial[12];

void setFactorial () {
    factorial[0] = 1;
    for (int i = 1; i < 12; i++) {
        factorial[i] = i * factorial[i - 1];
    }
}

double getProbability(double prob, int pow) {
    double P = 1;
    for (int i = 0; i < pow; i++) {
        P *= prob;
    }

    return P;
}

double getBinomial(int n, int k, double p) {
    double A = factorial[n] / (factorial[k] * factorial[n - k]);
    double B = getProbability(p, k);
    double C = getProbability(1 - p, n - k);
    return A * B * C;
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        int R, S, X, Y, W;
        scanf("%d %d %d %d %d", &R, &S, &X, &Y, &W);
        
        setFactorial();
        
        double win = 0;
        
        for (int k = X; k <= Y; k++) {
            int n = Y;
            double count = S - R + 1;
            double p = count / S;
            double bin = getBinomial(n, k, p);
            win += bin;
        }
        
        bool bet;
        
        if ((win * W) - 1 > 0) {
            bet = true;
        } else {
            bet = false;
        }
        
        printf("%s\n", bet ? "yes" : "no");
    }

    return 0;
}