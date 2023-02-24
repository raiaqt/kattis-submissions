#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int T;

    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int sum, diff;

        scanf("%d", &sum);
        scanf("%d", &diff);
        
        if ((sum - diff) % 2 == 1) {
            printf("impossible\n");
        } else {
            int y = (sum - diff) / 2;
            int x = sum - y;

            if (x >= 0 && y >= 0) {
                printf("%d %d\n", x, y);
            } else {
                printf("impossible\n");
            }
        }
       
    }

    return 0;
}