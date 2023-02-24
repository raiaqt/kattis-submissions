#include <cstdio>
#include <iostream>

using namespace std;

bool isPossible(int C, int n, int leave[], int enter[], int stay[]) {
    int space = C;

    for (int i = 0; i < n; i++) {
        space += leave[i];
        if (space > C) {
            return false;
        }

        space -= enter[i];
        if (space < 0) {
            return false;
        }
       
        if (space > 0 && stay[i] > 0) {
            return false;
        }
    }

    if (space != C) {
        return false;
    }

    return true;
}

int main() {
    int C, n;
    int leave[100];
    int enter[100];
    int stay[100];

    scanf("%d", &C);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &leave[i]);
        scanf("%d", &enter[i]);
        scanf("%d", &stay[i]);
    }

    bool possible = isPossible(C, n, leave, enter, stay);

    if (possible) {
        printf("possible\n");
    } else {
        printf("impossible\n");
    }

    return 0;
}