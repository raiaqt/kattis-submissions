#include <cstdio>

int isLess(char* a, char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i]) {
        i++;
    }

    return a[i] < b[i];
}

int isSame(char* a, char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i]) {
        i++;
    }

    return (a[i] == '\0') && (b[i] == '\0');
}

int main() {
    char exp[400];
    int stack[200];
    int pIndex[400];

    int e = 0;
    int s = 0;
    int p = 0;
    scanf("%s", exp);

    while(exp[e] != '\0') {
        pIndex[e] = -1;
        e++;
    }
    for (int i = e - 1; i >= 0; i--)  {
        if (exp[i] == ')') {
            // if right parenthesis, add to stack waiting for pairs
            stack[s++] = i;
        } else if (exp[i] == '(') {
            // if left parenthesis, remove right from stack, add to list of pairs
            int right = stack[--s];
            pIndex[right] = p;
            pIndex[i] = p;
            p++;
        }
    }


    int t = 1 << p;
    char **list = new char*[t + 100];
    bool *printed = new bool[t + 100];

    // iterate through all presence of left parenthesis
    for (int i = 0; i < t - 1; i++) {
        list[i] = new char[t + 100];
        int k = 0;
        for (int j = 0; j < e; j++) {
            bool numOp = pIndex[j] == -1 && exp[j] != 'N';
            if (numOp || (i & 1 << pIndex[j]) != 0) {
                // number or operation, or if bit is 1, add to result
                list[i][k++] = exp[j];
            }
        }
    }

    char *prev = new char[t + 100];
    for (int i = 0; i < t - 1; i++) {
        char *min = new char[t];
        int minIndex = -1;

        for (int j = 0; j < t - 1; j++) {
            if (!printed[j] && minIndex == -1) {
                min = list[j];
                minIndex = j;
            } else {
                if (!printed[j] && isLess(list[j], min)) {
                    min = list[j];
                    minIndex = j;
                }
            }
        }

        if (!isSame(min, prev)) {
            printf("%s\n", min);
            prev = min;
        }
        printed[minIndex] = true;
    }

    return 0;
}
