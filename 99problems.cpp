#include <cstdio>

int main()
{
    int num;
    scanf("%d", &num);
    
    int base = num / 100;
    
    if (num >= 100 && num % 100 < 49) {
        base--;
    }
    
    printf("%d\n", base * 100 + 99);
    return 0;
}
