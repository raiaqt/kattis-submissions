#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n, m, test;
    int qty[10];
    int reqs[10][30];
    int prize[10];
    int sticker[30];

    scanf("%d", &test);

    for (int t = 0; t < test; t++) {
        scanf("%d", &n);
        scanf("%d", &m);
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &qty[i]);

            for (int s = 0; s < qty[i]; s++) {
                scanf("%d", &reqs[i][s]);
            }
            scanf("%d", &prize[i]);
        }

        for (int j = 0; j < m; j++) {
            scanf("%d", &sticker[j]);
        }

        int totalPrize = 0;
        for (int i = 0; i < n; i++) {
            int min = 1000;
            for (int s = 0; s < qty[i]; s++) {
                int index = reqs[i][s] - 1;
                int stk = sticker[index];

                if (stk < min) {
                    min = stk;
                }
            }
            if (min < 1000) {
                totalPrize += prize[i] * min;
            }
        }

        printf("%d \n", totalPrize);
    }

    return 0;
}