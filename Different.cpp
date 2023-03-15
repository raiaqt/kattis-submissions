#include <cstdio>

const int max = 25;

char *A;
char *B;

bool shouldSwap(int aSize, int bSize)
{
    int i = 0;
    int j = 0;
    while (A[i] == '0')
        i++;
    while (B[j] == '0')
        j++;

    if (aSize - i < bSize - j)
        return true;
    if (aSize - i > bSize - j)
        return false;
    while (i < aSize)
    {
        if (A[i] < B[j])
            return true;
        if (A[i] > B[j])
            return false;
        i++;
        j++;
    }
    return false;
}

int main()
{
    A = new char[max];
    B = new char[max];

    while (scanf("%s %s", A, B) != EOF)
    {
        char *result = new char[max];
        int aSize = 0;
        int bSize = 0;

        while (A[aSize] != '\0')
            aSize++;
        while (B[bSize] != '\0')
            bSize++;

        // make aSize the higher number
        if (shouldSwap(aSize, bSize))
        {
            char *temp = new char[16];
            temp = A;
            int tempSize = aSize;
            A = B;
            aSize = bSize;
            B = temp;
            bSize = tempSize;
        }

        int i = aSize - 1; // last digit of A
        int j = bSize - 1; // last digit of B;
        result[aSize] = '\0';
        bool borrow = 0;
        while (i >= 0)
        {
            int a = A[i] - '0';
            int b = j >= 0 ? (B[j] - '0') : 0;
            int diff = a - b - borrow;
            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            result[i] = diff; // same index as A, guaranteed to fit
            i--;
            j--;
        }

        int r = 0;
        while (r != aSize && result[r] == 0)
            r++;
        if (r == aSize)
        {
            printf("%d", 0);
        }
        else
        {
            while (r < aSize)
            {
                printf("%d", result[r++]);
            }
        }
        printf("\n");

        A = new char[max];
        B = new char[max];
    }

    return 0;
}