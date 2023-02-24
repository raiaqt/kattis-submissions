#include <cstdio>
#include <iostream>

using namespace std;

int getRes(char c)
{
    if (c == 'h')
        return 1;
    if (c == 'l')
        return -1;
    return 0;
}

int main()
{

    int guess[2500];
    int res[2500];

    int num = 11;
    int ctr = 0;

    scanf("%d", &num);

    while (num > 0)
    {
        guess[ctr] = num;

        char str1[9];
        char str2[9];
        scanf("%s", str1);
        scanf("%s", str2);
        res[ctr] = getRes(str2[0]);
        ctr++;
        scanf("%d", &num);
    }

    int high = 11;
    int low = 0;
    for (int i = 0; i < ctr; i++) {
        if (res[i] == -1) {
            if (guess[i] > low) {
                low = guess[i];
            }
        }

        if (res[i] == 1) {
            if (guess[i] < high) {
                high = guess[i];
            }
        }

        if (res[i] == 0) {
            if (guess[i] < high && guess[i] > low) {
                printf("Stan may be honest\n");
            } else {
                printf("Stan is dishonest\n");
            }
            high = 11;
            low = 0;
        }
    }

    return 0;
}