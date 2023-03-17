#include <cstdio>

int main() {
    const int max = 200;
    char* line = new char[max];
  
    while (scanf("%[^\n]\n", line) != EOF) {
        int l = 0;
        bool pressed0 = false;
        bool pressed1 = false;

        while (line[l] != '\0') {
            for (int i = 0; i < 7; i++) {
                if (line[l] & (1 << i)){
                    pressed1 = !pressed1;
                } else {
                    pressed0 = !pressed0;
                }
            }
            l++;
        }
        
        printf("%s\n", (!pressed1 && !pressed0) ? "free" : "trapped");
    } 

    return 0;
}