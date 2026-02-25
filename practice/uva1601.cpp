#include<bits/stdc++.h>
using namespace std;
const int maxn = 150;
int ID(int a, int b, int c) {
	return (a << 16) | (b << 8) | c;
}
bool conflict(int a, int a2, int b, int b2) {
	return a2 == b2 || (a2 == b&&b2 == a);
}
int dis[maxn][maxn][maxn];
int main() {
	char maze[20][20];
	int w, h, n;
	while (scanf("%d%d%d\n", &w, &h, &n) == 3 && w) {
		for (int i = 0; i < h; i++)
			fgets(maze[i], 20, stdin);
		int x[maxn] = {0}, y[maxn] = {0}, cnt = 0, idd[20][20] = {0};
		int dx[] = {0, 1, -1, 0, 0}, dy[] = {0, 0, 0, 1, -1}, s[3], t[3];
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (maze[i][j] != '#') {
					x[cnt] = i;
					y[cnt] = j;
					idd[i][j] = cnt;
					if (islower(maze[i][j]))
						s[maze[i][j] - 'a'] = cnt;
					if (isupper(maze[i][j]))
						t[maze[i][j] - 'A'] = cnt;
					cnt++;
				}
		int G[maxn][5] = {0}, sum[maxn] = {0};
		for (int i = 0; i < cnt; i++)
			for (int j = 0; j < 5; j++) {
				int nx = x[i] + dx[j];
				int ny = y[i] + dy[j];
				if (maze[nx][ny] != '#') {
					G[i][sum[i]++] = idd[nx][ny];
				}
			}
		if (n <= 2) {
			s[2] = t[2] = cnt;
			sum[cnt] = 1;
			G[cnt][0] = cnt;
			cnt++;
		}
		if (n <= 1) {
			s[1] = t[1] = cnt;
			sum[cnt] = 1;
			G[cnt][0] = cnt;
		}
		queue<int>q;

		memset(dis, -1, sizeof(dis));
		dis[s[0]][s[1]][s[2]] = 0;
		q.push(ID(s[0], s[1], s[2]));
		while (!q.empty()) {
			int m = q.front();
			q.pop();
			int a = (m >> 16) & 0xff, b = (m >> 8) & 0xff, c = m & 0xff;
			if (a == t[0] && b == t[1] && c == t[2]) {
				break;
			}
			for (int i = 0; i < sum[a]; i++) {
				int a2 = G[a][i];
				for (int j = 0; j < sum[b]; j++) {
					int b2 = G[b][j];
					if (conflict(a, a2, b, b2))
						continue;
					for (int k = 0; k < sum[c]; k++) {
						int c2 = G[c][k];
						if (conflict(a, a2, c, c2))
							continue;
						if (conflict(b, b2, c, c2))
							continue;
						if (dis[a2][b2][c2] >= 0)
							continue;
						q.push(ID(a2, b2, c2));
						dis[a2][b2][c2] = dis[a][b][c] + 1;
					}
				}
			}
		}
		printf("%d\n",dis[t[0]][t[1]][t[2]]);
	}
}
