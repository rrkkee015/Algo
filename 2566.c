#include <stdio.h>

int r, ry, rx;

int tmp;

void input() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			scanf("%d", &tmp);
			if (tmp > r) {
				r = tmp;
				ry = i;
				rx = j;
			}
		}
	}
}

int main(void) {
	input();
	printf("%d\n%d %d", r, ry + 1, rx + 1);
	return 0;
}