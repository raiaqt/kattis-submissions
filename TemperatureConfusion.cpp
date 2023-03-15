#include <cstdio>

int gcd(int n, int d) {
    while (d != 0) {
        int temp = d;
        d = n % d;
        n = temp;
    }
    return n;
}

bool isNegative(int* n) {
    if (*n < 0) {
        *n = *n * -1;
        return true;
    }
    return false;
}

void solve() {
    char input[40];
    
    scanf("%s", input);
    
    int a = 0;
    int b = 0;
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
    
    int g1 = gcd(a, b);
    a /= g1;
    b /= g1;
    a = negative ? a * -1 : a;
    int num = 45 * a - 1440 * b;
    int denum = 81 * b;
    
    int g = gcd(num, denum);
    num /= g;
    denum /= g;
    
    int neg = false;
    printf("num %d %d\n", num, denum);
    if (isNegative(num)) {
        neg = !neg;
    }
    if (isNegative(denum)) {
        neg = !neg;
    }
    
    printf("%s%d/%d\n", neg ? "-" : "", num, denum);
    
    float f = (float)num / (float)denum;
    printf("%s%f\n", neg ? "-" : "", f);

}
int main() {
    while (true) {
        solve();
    }
    return 0;
}