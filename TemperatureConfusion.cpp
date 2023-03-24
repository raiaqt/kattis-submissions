#include <cstdio>

long gcd(long n, long d) {
    while (d != 0) {
        long temp = d;
        d = n % d;
        n = temp;
    }
    return n;
}

void solve() {
    char input[40];
    
    scanf("%s", input);
    
    long a = 0;
    long b = 0;
    bool negative;
    
    int i = 0;
    if (input[i] == '-') {
        negative = true;
        i++;
    }
        
    while (input[i] != '\0')
        i++;
    
    long mult = 1;
    i--;

    while (input[i] != '/') {
        b += (input[i--] - '0') * mult;
        mult *= 10;
    }
    mult = 1;
    i--;
    while (i >= (0 + negative)) {
        a += (input[i--] - '0') * mult;
        mult *= 10;
    }
    
    long g1 = gcd(a, b);
    a /= g1;
    b /= g1;
    a = negative ? a * -1 : a;
    long num = 45 * a - 1440 * b;
    long denum = 81 * b;
    
    long g = gcd(num, denum);
    num /= g;
    denum /= g;
    
    if (denum < 0) {
        denum *= -1;
        num *= -1;
    }
    
    printf("%ld/%ld\n", num, denum);
}

int main() {
    solve();
    return 0;
}