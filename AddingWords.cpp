#include <cstdio>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	char command[5];
	char lookup[2010][35];
	unordered_map<string, int> map;

	char x[35];
	int y;
	char op[2];

	while (scanf("%s", command) != EOF) {
		if (command[1] == 'e') {			// def
			scanf("%s %d", x, &y);

			for (int i = 0; i < 35; i++) {
				lookup[y + 1000][i] = x[i];
			}
			map[x] = y;

		} else if (command[1] == 'a') {		// calc
			bool unknown = false;
			int r = 0;
			scanf("%s %s", x, op);

			if (map.find(x) == map.end()) {
				unknown = true;
			} else {
				r += map[x];
			}
			printf("%s %s ", x, op);

			while (op[0] != '=') {
				scanf("%s", x);

				if (op[0] == '+') {
					if (map.find(x) == map.end()) {
						unknown = true;
					} else {
						r += map[x];
					}
				} else {
					if (map.find(x) == map.end()) {
						unknown = true;
					} else {
						r -= map[x];
					}
				}

				scanf("%s", op);
				printf("%s %s ", x, op);
			}

			if (!unknown && (lookup[r + 1000][0] >= 'a' && lookup[r + 1000][0] <= 'z')) {
				printf("%s\n", lookup[r + 1000]);
			} else {
				printf("unknown\n");
			}
		} else {							// clear
			map.clear();
		}
	}

	return 0;
}
