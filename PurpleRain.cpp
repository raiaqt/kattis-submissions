#include <cstdio>

int main() {
    const int maxN = 100005;
    char rain[maxN];
    
    scanf("%s", rain);
    
    int size = 0;
    int diff[maxN];      // positive if R > B, negative if B > R

    while (rain[size] != '\0') {
        if (rain[size] == 'R') {
            diff[size + 1] = diff[size] + 1;
        } else {
            diff[size + 1] = diff[size] - 1;
        }
        size++;
    }
    
    size++;
    int max = 0;
    int min = 0;
    int maxIn = 0;
    int minIn = 0;
    
    for (int i = 0; i < size; i++) {
        if (diff[i] > max) {
            max = diff[i];
            maxIn = i;
        }
        if (diff[i] < min) {
            min = diff[i];
            minIn = i;
        }
    }
    
    int start = maxIn < minIn ? maxIn + 1 : minIn + 1;
    int end = maxIn > minIn ? maxIn : minIn;
    
    printf("%d %d\n", start, end);
    return 0;
}