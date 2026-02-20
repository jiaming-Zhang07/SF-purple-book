//用数组形式表示队列，同样是bfs.
#include<bits/stdc++.h>
using namespace std;
using state = int[9];
const int maxn = 1000001;
state st[maxn], goal;
int dist[maxn];
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
int code(int t[9]) {
	int v = 0;
	for (int i = 0; i < 9; i++) {
		v = v * 10 + t[i];
	}
	return v;
}
int head[maxn], nex[maxn];
bool vis[362880];
int fact[9];
int has(state& s) {
	int v = 0;
	for (int i = 0; i < 9; i++)
		v = v * 10 + s[i];
	return v % maxn;
}
int try_insert(int s) {
	int h = has(st[s]);
	int u = head[h];
	while (u) {
		if (memcmp(st[s], st[u], sizeof(st[u])) == 0)
			return 0;
		u=nex[u];
	}
	nex[s] = head[h];
	head[h] = s;
	return 1;
}

int main() {
	memset(nex, 0, sizeof(nex));
	memset(head, 0, sizeof(head));
	fact[0] = 1;
	for (int i = 1; i < 9; i++)
		fact[i] = fact[i - 1] * i;
	for (int i = 0; i < 9; i++)
		scanf("%d", &st[1][i]);
	for (int i = 0; i < 9; i++)
		scanf("%d", &goal[i]);
	int front = 1, rear = 2;
	
	while (front < rear) {
		state&s = st[front];
		if (memcmp(s, goal, sizeof(goal)) == 0)
			break;
		int x;
		for ( x = 0; x < 9; x++)
			if (!s[x])
				break;
		int r = x / 3;
		int c = x % 3;
		for (int i = 0; i < 4; i++)
			if (r + dr[i] < 3 && r + dr[i] >= 0 && c + dc[i] < 3 && c + dc[i] >= 0) {
				state&t = st[rear];
				memcpy(&t, &s, sizeof(s));
				t[x] = s[3 * (r + dr[i]) + c + dc[i]];
				t[3 * (r + dr[i]) + c + dc[i]] = s[x];
				if (try_insert(rear)) {
					dist[rear] = dist[front] + 1;
					rear++;
				}
			}
		front++;
	}
	if (front == rear)
		printf("-1\n");
	else
		printf("%d\n", dist[front]);
}
