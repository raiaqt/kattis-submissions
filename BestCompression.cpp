#include <cstdio>

int main() {
    long long int N;
    int b;
    long long int one = 1;

    scanf("%lld %d", &N, &b);

    long long int space = one << (b + 1);
    printf("%s", space > N ? "yes" : "no");
}
