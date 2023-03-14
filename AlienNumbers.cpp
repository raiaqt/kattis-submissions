#include <cstdio>

char decToSource[100];
char sourceToDec[200];
char decToTarget[100];
char targetToDec[200];

int getSize(char* num) {
    int i = 0;
    while (num[i] != '\0') {
        i++;
    }
    
    return i;
}

int toDecimal(char* num, int base) {
    int decimal = 0;
    int b = 1;
    int sz = getSize(num);
    
    for (int i = sz - 1; i >= 0; i--) {
        int val = sourceToDec[num[i]];
        decimal += (val * b);
        b *= base;
    }
    
    return decimal;
}

char* toTarget(int decimal, int base) {
    char* revTarget = new char[40];
    char* target = new char[40];
    int i = 0;
    int d = decimal;
    
    while (d > 0) {
        int decDigit = d % base;
        revTarget[i++] = decToTarget[decDigit];
        d /= base;
    }
    for (int j = 0; j < i; j++) {
        target[j] = revTarget[i - j - 1];
    }
    target[i] = '\0'; 
    return target;
}

int main() {
    int T;
    
    scanf("%d", &T);
    
    char* sourceNum = new char[40];
    char* targetNum = new char[40];
    
    int sourceBase, targetBase;

    for (int t = 1; t <= T; t++) {
        scanf("%s %s %s", sourceNum, decToSource, decToTarget);
        
        sourceBase = 0;
        targetBase = 0;
        int i = 0;
        while (decToSource[i] != '\0') {
            char digit = decToSource[i];
            sourceToDec[digit] = i++;
            sourceBase++;
        }
        i = 0;
        while (decToTarget[i] != '\0') {
            char digit = decToTarget[i];
            targetToDec[digit] = i++;
            targetBase++;
        }
        
        int decimal = toDecimal(sourceNum, sourceBase);
        targetNum = toTarget(decimal, targetBase);
        
        printf("Case #%d: %s\n", t, targetNum);
    }

    return 0;
}