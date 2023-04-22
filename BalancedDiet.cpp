#include <cstdio>
#include <cmath>

int main() {
    int size, total;
    int calories[25];

    scanf("%d", &size);
    while (size > 0) {
    	total = 0;
    	for (int i = 0; i < size; i++) {
    		scanf("%d\n", &calories[i]);
    		total += calories[i];
    	}

    	int C = 1 << (size - 1);

    	int totalCalories[C];
    	totalCalories[0] = 0;

    	int min = 600 * 25;
    	int first, second;

    	for (int n = 1; n <= C; n++) {
    		int lsOne = n & (-n);
    		int prev = n - lsOne;
    		int index = log2(lsOne);

    		int curr = totalCalories[prev] + calories[index];

    		totalCalories[n] = curr;
    		int comp = total - curr;

    		int diff = curr - comp;
    		if (diff < 0) {
    			diff *= -1;
    		}

    		if (diff < min) {
    			min = diff;
    			first = curr >= comp ? curr : comp;
    			second = curr < comp ? curr : comp;
    		}
    	}

    	printf("%d %d\n", first, second);
        scanf("%d", &size);
    }
    return 0;
}
