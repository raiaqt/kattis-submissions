#include <cstdio>

int getPoints(char c) {
	if (c == 'R') {
		return 1;
	}
	if (c == 'B') {
		return 1 << 1;
	}
	if (c == 'L') {
		return 1 << 2;
	}
	return 0;
}

char getCounter(char c) {
	if (c == 'R') {
		return 'S';
	}
	if (c == 'B') {
		return 'K';
	}
	return 'H';
}

int main() {
	const int length = 1000010;
	char* monster = new char[length];
	char* mech = new char[length];

	scanf("%s", monster);

	int code = 0;
	int i = 0;
	int j = 0;

	for (int m = 0; m < 3; m++) {
		code += getPoints(monster[m]);
	}

	while (monster[i] != '\0') {
		if (code == (1 << 3) - 1) {
			mech[j++] = 'C';
			i += 3;

			code = 0;
			for (int m = i; m < i + 3; m++) {
				code += getPoints(monster[m]);
			}
		} else {
			mech[j++] = getCounter(monster[i]);
			code -= getPoints(monster[i]);
			code += getPoints(monster[i + 3]);
			i++;
		}
	}

	printf("%s", mech);
	return 0;
}
