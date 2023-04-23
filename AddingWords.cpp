#include <cstdio>
#include <unordered_map>
using namespace std;

int main() {
	char command[5];
	char lookup[2010][35];
	unordered_map<char*, int> map;

	char x[35];
	int y;
	char op[2];

	while (scanf("%s", command) != EOF) {
		if (command[0] == '0') {
			break;
		}
		if (command[1] == 'e') {			// def
			scanf("%s %d", x, &y);

			for (int i = 0; i < 35; i++) {
				lookup[y + 1000][i] = x[i];
			}
			map[x] = y;
		} else if (command[1] == 'a') {		// calc
			scanf("%s %s", x, op);
			int r = map[x];

			printf("%s %s ", x, op);

			while (op[0] != '=') {
				scanf("%s", x);

				printf("%d, r\n", r);
				if (op[0] == '+') {
					r += map[x];
				} else {
					r -= map[x];
				}

				scanf("%s", op);
				printf("%s %s ", x, op);
			}

			if (lookup[r + 1000][0] >= 'a' && lookup[r + 1000][0] <= 'z') {
				printf("%s\n", lookup[r]);
			} else {
				printf("unknown\n");
			}
		} else {							// clear

		}
	}

	printf("done");
	return 0;
}
