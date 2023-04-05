#include <cstdio>

int main() {
	const char PER[3] = {'P', 'E', 'R'};
    char text[305];

    scanf("%s", text);

    int i = 0;
    int changes = 0;

    while (text[i] != '\0') {
    	if (text[i] != PER[i % 3]) {
    		changes++;
    	}
    	i++;
    }

    printf("%d\n", changes);
    return 0;
}
