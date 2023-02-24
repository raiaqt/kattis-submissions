#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    const int maxSize = 2000005;
    const int mid = maxSize / 2;
    
    int *backQ = new int[maxSize];
    int *frontQ = new int[maxSize];
    int backTail = mid;
    int backHead = mid;
    int frontTail = mid;
    int frontHead = mid;
    
    int totalSize = 0;
    
    int N, num;
    char command[12];
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%s %d", command, &num);
        
        int backSize = backHead - backTail;
        int frontSize = frontHead - frontTail;
        
        totalSize++;
        if (command[0] == 'g') {
            int answer;
            if (num < frontSize) {
                int index = frontTail + num;
                answer = frontQ[index];
            } else {
                int index = backTail + num - frontSize;
                answer = backQ[index];
            }
            
            printf("%d\n", answer);
        } else {
            if (command[5] == 'b') {
                backQ[backHead] = num;
                backHead++;
                backSize++;
                
                if (backSize - frontSize > 0) {
                    frontQ[frontHead] = backQ[backTail];
                    backTail++;
                    frontHead++;
                    backSize--;
                    frontSize++;
                }
            }
            if (command[5] == 'f') {
                frontTail--;
                frontQ[frontTail] = num;
                frontSize++;
                if (frontSize - backSize > 1) {
                    backTail--;
                    backQ[backTail] = frontQ[frontHead - 1];
                    frontHead--;
                    backSize++;
                    frontSize--;
                }
            }
            if (command[5] == 'm') {
                if (frontSize == backSize) {
                    frontQ[frontHead] = num;
                    frontHead++;
                    frontSize++;
                } else {    // frontSize > backSize
                    backTail--;
                    backQ[backTail] = num;
                    backSize++;
                }
            }
        }
    }
   
   return 0;
}
