#include <cstdio>

int main() {

	int count[2][13][60];
	char time[20];
	char m[20];
	int N;
	scanf("%d", &N);

	while (N != 0) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 13; j++) {
				for (int k = 0; k < 60; k++) {
					count[i][j][k] = 0;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			scanf("%s %s", time, m);

			int hr = 0;
			int min = 0;
			int half = 0;
			int s;
			if (time[1] == ':') {
				hr = time[0] - '0';
				s = 1;
			} else {
				hr += (time[0] - '0') * 10;
				hr += time[1] - '0';
				s = 2;
			}
			s++;
			min += (time[s++] - '0') * 10;
			min += (time[s++] - '0');
			s += 2;

			if (m[0] == 'a') {
				half = 0;
			} else {
				half = 1;
			}

			count[half][hr % 12][min]++;
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 13; j++) {
				for (int k = 0; k < 60; k++) {
					for (int n = 0; n < count[i][j][k]; n++) {
						printf("%d:%02d ", j == 0 ? 12 : j, k);
						printf("%s\n", i == 0 ? "a.m." : "p.m.");
					}
				}
			}
		}

		printf("\n");
		scanf("%d", &N);
	}
	return 0;
}
