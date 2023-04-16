#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);

	int n;
	double x, y;
	double cx;
	double cy;
	double r = 8 * 8;

	for (int t = 0; t < T; t++) {
		scanf("%lf %lf", &x, &y);
		scanf("%d", &n);

		bool result = false;

		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &cx, &cy);

			double dx = x - cx;
			dx *= dx;

			double dy = y - cy;
			dy *= dy;

			if (dx + dy <= r) {
				result = true;
			}
		}

		printf("%s\n", result ? "light a candle" : "curse the darkness");
	}
    return 0;
}
