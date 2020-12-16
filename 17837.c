#define FLOOR 2
#include <stdio.h>

int N, K;
int map[20][20][20]; // 0 : 색, 1 : 갯수, 2~: 순서
int hor[11][3]; // y, x, dir
int *stack;
int turn, result;

int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

int re[5] = { 0, 2, 1, 4, 3 };

int is_bw(int ny, int nx) {
	if (map[ny][nx][0] == -1 || map[ny][nx][0] == 2) return 1;
	return 0;
}

int find(int num, int y, int x) {
	for (int n = FLOOR; n < map[y][x][1]; ++n) {
		if (num == map[y][x][n]) return n;
	}
}

void move(int num, int y, int x, int dir) {
	int ny, nx, ndir;

	ndir = hor[num][2];
	ny = y + dy[ndir];
	nx = x + dx[ndir];

	if (is_bw(ny, nx)) {
		ndir = re[ndir];
		ny = y + dy[ndir];
		nx = x + dx[ndir];
		hor[num][2] = ndir;
		if (is_bw(ny, nx)) {
			return;
		}
	}
	if (map[ny][nx][0] == 0) {
		int cur = find(num, y, x);
		int c;
		for (c = cur; c < 20; c++) {
			if (map[y][x][c] == 0) break;
			map[ny][nx][map[ny][nx][1]++] = map[y][x][c];
			hor[map[y][x][c]][0] = ny;
			hor[map[y][x][c]][1] = nx;
			map[y][x][c] = 0;
			map[y][x][1]--;
		}
	}
	else if (map[ny][nx][0] == 1) {
		int cur = find(num, y, x);
		for (int c = map[y][x][1] - 1; c >= cur; c--) {
			map[ny][nx][map[ny][nx][1]++] = map[y][x][c];
			hor[map[y][x][c]][0] = ny;
			hor[map[y][x][c]][1] = nx;
			map[y][x][c] = 0;
			map[y][x][1]--;
		}
	}

}

void init() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i <= N + 1; ++i) {
		for (int j = 0; j <= N + 1; ++j) {
			if (i == 0 || j == 0 || i == N + 1 || j == N + 1) {
				map[i][j][0] = -1;
			}
			else {
				scanf("%d", &map[i][j][0]);
			}
			map[i][j][1] = FLOOR;
		}
	}
	for (int k = 1; k <= K; ++k) {
		scanf("%d %d %d", &hor[k][0], &hor[k][1], &hor[k][2]);
		stack = &map[hor[k][0]][hor[k][1]][1];
		map[hor[k][0]][hor[k][1]][*stack] = k;
		*stack += 1;
	}
}

void solve() {
	while (true) {
		turn += 1;
		if (turn > 1000) {
			result = -1;
			return;
		}
		for (int k = 1; k <= K; ++k) {
			move(k, hor[k][0], hor[k][1], hor[k][2]);
			if (map[hor[k][0]][hor[k][1]][1] >= 6) {
				result = turn;
				return;
			}
		}
	}
}

int main(void) {
	// freopen("input.txt", "r", stdin);
	init();

	solve();

	printf("%d", result);
	return 0;
}