#include <cstdio>

int main() {
    char A[1005];
    char B[1005];

    scanf("%s %s", A, B);

    int i = 0;
    int j = 0;
    while(A[i] != 'h') {
        i++;
    }
    while(B[j] != 'h') {
        j++;
    }

    printf("%s\n", i >= j ? "go" : "no");
    return 0;
}
