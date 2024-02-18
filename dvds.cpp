#include <cstdio>

int N;
int arr[1000005];

int main()
{
    int T;
    scanf("%d\n", &T);
    
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }   
        
        int target = 1;
        for (int i = 0; i < N; i++) {
            if (arr[i] == target) {
                target++;
            }
        }
        
        int result = N - target + 1;
        
        printf("%d\n", result);
    }
    
    return 0;
}
