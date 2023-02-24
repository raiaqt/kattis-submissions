#include <iostream>

int main() {
    // Write C++ code here
    int n;
    int stack[200005];
    int top = 0;

    scanf("%d", &n);
    
    for (int i = 0; i < n * 2; i++) {
        int sock;
        scanf("%d", &sock);
        
        if (top == 0 || sock != stack[top - 1]) {
            stack[top] = sock;
            top++;
        } else {
            top--;          // pair, remove from stack
        }
    }
    
    if (top == 0) {
        printf("%d\n", n * 2);
    } else {
        printf("impossible\n");
    }
    return 0;
}