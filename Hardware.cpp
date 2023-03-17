// Online C++ compiler to run C++ program online
#include <iostream>

int main() {
    int T;
    char temp;
    char roadName[100];
    char addresses[12];
    int total;
        
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%c %[^\n]", &temp, roadName);
        scanf("%d %s", &total, addresses);
        int houseCount = 0;
        int digitCount[10];
        
        for (int i = 0; i < 10; i++) {
            digitCount[i] = 0;
        }
        
        while (houseCount < total) {
            char in;
            char s;
            scanf("%c %c",&s, &in);
            if(in == '+') {
                int start, end, interval;
                scanf("%d %d %d", &start, &end, &interval);
                
                for (int i = start; i <= end; i+= interval) {
                    int house = i;
                    int base = 10;
                    while (house > 0) {
                        int digit = house % base;
                        digitCount[digit]++;
                        house /= base;
                    }
                    houseCount++;
                }
            } else {
                char* house = new char[12];
                scanf("%[^\n]", house);
                
                int digit = in - '0';
                digitCount[digit]++;
                int i = 0;
                while (house[i] != '\0') {
                    digit = house[i++] - '0';
                    digitCount[digit]++;
                }
                houseCount++;
            }
        }
        
        int totalDigits = 0;
        printf("%s\n", roadName);
        printf("%d address%s\n", total, total == 1 ? "" : "es");
        for (int i = 0; i < 10; i++) {
            printf("Make %d digit %d\n", digitCount[i], i);
            totalDigits += digitCount[i];
        }
        printf("In total %d digit%s\n", totalDigits, totalDigits == 1 ? "" : "s");
    }
    return 0;
}