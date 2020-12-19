#define MAX_NUM 100000
#include <stdio.h>

int arr[10][10];
int visited[10][10][MAX_NUM];

int result;

int dy[10] = { -1, -1, -1, 0, 1, 1, 1, 0, 0 };
int dx[10] = { -1, 0, 1, 1, 1, 0, -1, -1, 0 };

int now;

struct node {
	int y;
	int x;
	int t;
} NODE[MAX_NUM];

int h, t;

void init_arr() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (i == 0 || j == 0 || i == 9 || j == 9) {
				arr[i][j] = 1;
			}
		}
	}
}

void input() {
	char bod[10];
	for (int i = 1; i <= 8; ++i) {
		scanf("%s", bod);
		for (int j = 1; j <= 8; ++j) {
			if (bod[j - 1] == '.') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}

	init_arr();
}

void move_arr() {
	for (int i = 1; i <= 8; ++i) {
		for (int j = 8; j >= 1; --j) {
			arr[j][i] = arr[j - 1][i];
		}
	}
	for (int i = 1; i <= 8; ++i) {
		arr[1][i] = 0;
	}
}

void print() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void BFS() {
	node init, cur;
	init.y = 8; init.x = 1; init.t = 0;
	now = t;
	NODE[t++] = init;
	visited[init.y][init.x][init.t] = 1;

	while (h != t) {
		cur = NODE[h++];
		if (cur.y == 1 && cur.x == 8) {
			result = 1;
			return;
		}
		if (cur.t != now) {
			now = cur.t;
			move_arr();
		}
		if (arr[cur.y][cur.x] == 1) continue;
		for (int i = 0; i < 10; ++i) {
			node tmp;
			tmp.y = cur.y + dy[i]; tmp.x = cur.x + dx[i]; tmp.t = cur.t + 1;
			if (arr[tmp.y][tmp.x] != 1 && !visited[tmp.y][tmp.x][tmp.t]) {
				visited[tmp.y][tmp.x][tmp.t] = 1;
				NODE[t++] = tmp;
			}
		}
	}
}

int main(void) {
	// freopen("input.txt", "r", stdin);
	input();
	BFS();
	printf("%d", result);
	return 0;
}