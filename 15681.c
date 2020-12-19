#include <stdio.h>

int N, R, Q;
int visited[100010];
int cnt[100010];

struct node {
	int num;
	node* nxt;
} NODE[500050];

int _idx;

node* myalloc() {
	return &NODE[_idx++];
}

node* arr[100010];
node* tree[100010];

void init() {
	for (int n = 1; n <= N; ++n) {
		arr[n] = myalloc();
		arr[n]->num = -1;
		arr[n]->nxt = nullptr;

		tree[n] = myalloc();
		tree[n]->num = -1;
		tree[n]->nxt = nullptr;

		cnt[n] = 1;
	}
}

void push(int idx, int val, node* _arr[]) {
	node* cur = myalloc();
	cur->num = val;
	cur->nxt = _arr[idx]->nxt;
	_arr[idx]->nxt = cur;
}

void input() {
	for (int n = 1; n < N; ++n) {
		int a, b;
		scanf("%d %d", &a, &b);
		push(a, b, arr);
		push(b, a, arr);
	}
}

void makeTree(int curNode) {
	visited[curNode] = 1;
	node* cur = arr[curNode]->nxt;
	while (cur) {
		if (!visited[cur->num]) {
			push(curNode, cur->num, tree);
			makeTree(cur->num);
		}
		cur = cur->nxt;
	}
}

int countNode(int curNode) {
	node* cur = tree[curNode]->nxt;
	if (!cur) {
		return cnt[curNode];
	}
	else {
		int tmp = 0;
		while (cur) {
			tmp += countNode(cur->num);
			cur = cur->nxt;
		}
		cnt[curNode] += tmp;
		return cnt[curNode];
	}
}

void query(int q) {
	printf("%d\n", cnt[q]);
}

int main(void) {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &R, &Q);
	init();
	input();
	makeTree(R);
	countNode(R);
	for (int q = 1; q <= Q; ++q) {
		int _q;
		scanf("%d", &_q);
		query(_q);
	}
	return 0;
}