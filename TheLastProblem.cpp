#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    char name[51];

    scanf("%[^\n]s", name);
    
    printf("Thank you, %s, and farewell!", name);

    return 0;

}