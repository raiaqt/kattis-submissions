#include <cstdio>

int num[3];

void compare(int a, int b) {
    if (num[a] > num[b]) {
        int temp = num[a];
        num[a] = num[b];
        num[b] = temp;
    }
}

int main() {
    
    scanf("%d %d %d", &num[0], &num[1], &num[2]);
    
    compare(0, 1);
    compare(1, 2);
    compare(0, 1);
    
    char letters[3];
    
    scanf("%s", letters);
    
    for (int i = 0; i < 3; i++) {
        int index = letters[i] - 'A';
        printf("%d", num[index]);
        if (i < 2)
            printf(" ");
    }

    return 0;
}