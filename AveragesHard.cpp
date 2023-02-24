#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int T, Ncs, Ne;
    int IQcs[200000];

    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("\n");

        scanf("%d %d", &Ncs, &Ne);

        for (int i = 0; i < Ncs; i++) {
            scanf("%d", &IQcs[i]);
        }

        double Ae = 0;
        for (int i = 0; i < Ne; i++) {
            int IQ;
            scanf("%d", &IQ);
            Ae += IQ;
        }
        Ae /= Ne;

        // get average
        double Acs = 0;
        for (int i = 0; i < Ncs; i++) {
            Acs += IQcs[i];
        }
        Acs /= Ncs;      

        int total = 0;
        for (int i = 0; i < Ncs; i++) {
            if (IQcs[i] < Acs && IQcs[i] > Ae) {
                total++;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}
