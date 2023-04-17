#include <cstdio>

int H[3];
int W[3];

bool canMake(int s1, int s2) {
    int s, s3;
    if (H[1] == s1 || W[1] == s1) {
        s = s1;
        if (H[1] == s1) {
            s3 = s2 - W[1];
        } else {
            s3 = s2 - H[1];
        }
    } else if (H[1] == s2 || W[1] == s2) {
        s = s2;
        if (H[1] == s2) {
            s3 = s1 - W[1];
        } else {
            s3 = s1 - H[1];
        }
    } else {
        return false;
    }
    
    if ((H[2] == s && W[2] == s3) || (H[2] == s3 && W[2] == s))
        return true;
    
    return false;
}

int main() {
    
    for (int i = 0; i < 3; i++) {
        scanf("%d", &H[i]);
        scanf("%d", &W[i]);
    }
    
    int s1 = H[0];
    int s2 = s1 - W[0];
    
    printf("%s\n", canMake(s1, s2) ? "YES" : "NO");

    return 0;
}