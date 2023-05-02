#include <cstdio>

float getSameTime(float sa, float va, float sd, float vd) {
    return (sd - sa) / (va - vd);
}

int main() {
    float ans = getSameTime(0, 1 / 1.1, 10, -1);
    
    printf("%f\n", ans);
    return 0;
}