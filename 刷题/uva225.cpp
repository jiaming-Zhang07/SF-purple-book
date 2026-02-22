#include<bits/stdc++.h>
using namespace std;
struct dot {
	int x, y;
	bool operator<(const dot&other)const {
		return tie(x, y) < tie(other.x, other.y);
	}
};
char ch[] = {'\0', 'n', 'w', 'e', 's'};
int maxl;

int c[21];
int cnt;
int vis[250][250];
void dfs(int point, int d, dot dot2) {
	if ((maxl + d) * (maxl - d + 1) / 2 < abs(dot2.x) + abs(dot2.y))
		return;
	if (dot2.x == 0 && dot2.y == 0 && d == maxl + 1 ) {
		for (int i = 1; i <= d - 1; i++)
			printf("%c", ch[c[i]]);
		printf("\n");
		cnt++;
		return;
	}
	if (d == maxl + 1)
		return;
	if (point == 1 || point == 4) {
		int i;
		for ( i = 1; i <= d; i++) {
			if (vis[125 + dot2.x + i][125 + dot2.y]) {
				goto jump;
			}
		}
		c[d] = 3;
		vis[125 + dot2.x + d][125 + dot2.y] = 1;
		dfs(3, d + 1, dot{dot2.x + d, dot2.y});
		vis[125 + dot2.x + d][125 + dot2.y] = 0;
jump:
		for ( i = 1; i <= d; i++) {
			if (vis[125 + dot2.x - i][125 + dot2.y]) {
				goto jump4;
			}
		}
		c[d] = 2;
		vis[125 + dot2.x - d][125 + dot2.y] = 1;
		dfs(2, d + 1, dot{dot2.x - d, dot2.y});
		vis[125 + dot2.x - d][125 + dot2.y] = 0;
jump4:
		;
	} else if (point == 2 || point == 3) {
		int i;
		for ( i = 1; i <= d; i++) {
			if (vis[125 + dot2.x][125 + dot2.y + i])
				goto jump2;
		}
		c[d] = 1;
		vis[125 + dot2.x][125 + dot2.y + d] = 1;
		dfs(1, d + 1, dot{dot2.x, dot2.y + d});
		vis[125 + dot2.x][125 + dot2.y + d] = 0;
jump2:
		for ( i = 1; i <= d; i++) {
			if (vis[125 + dot2.x][125 + dot2.y - i])
				goto jump3;
		}
		c[d] = 4;
		vis[125 + dot2.x][125 + dot2.y - d] = 1;
		dfs(4, d + 1, dot{dot2.x, dot2.y - d});
		vis[125 + dot2.x][125 + dot2.y - d] = 0;
jump3:
		;
	}
}
int main() {freopen("z.txt", "r", stdin);
	freopen("zjm.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		int  m;
		scanf("%d%d", &maxl, &m);
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			vis[125 + x][125 + y] = 1;
		}
		dot dot2{0, 0 };
		int d = 1;
		int i;
		for ( i = 1; i <= d; i++) {
			if (vis[125 + dot2.x + i][125 + dot2.y]) {
				goto jump;
			}
		}
		c[d] = 3;
		vis[125 + dot2.x + d][125 + dot2.y] = 1;
		dfs(3, d + 1, dot{dot2.x + d, dot2.y});
		vis[125 + dot2.x + d][125 + dot2.y] = 0;
jump:
		for ( i = 1; i <= d; i++) {
			if (vis[125 + dot2.x][125 + dot2.y + i]) {
				goto jump2;
			}
		}
		c[d] = 1;
		vis[125 + dot2.x][125 + dot2.y + d] = 1;
		dfs(1, d + 1, dot{dot2.x, dot2.y + d});
		vis[125 + dot2.x][125 + dot2.y + d] = 0;
jump2:
		for ( i = 1; i <= d; i++) {
			if (vis[125 + dot2.x][125 + dot2.y - i]) {
				goto jump3;
			}
		}
		c[d] = 4;
		vis[125 + dot2.x][125 + dot2.y - d] = 1;
		dfs(4, d + 1, dot{dot2.x, dot2.y - d});
		vis[125 + dot2.x][125 + dot2.y - d] = 0;
jump3:
		for ( i = 1; i <= d; i++) {
			if (vis[125 + dot2.x - i][125 + dot2.y]) {
				goto jump4;
			}
		}
		c[d] = 2;
		vis[125 + dot2.x - d][125 + dot2.y] = 1;
		dfs(2, d + 1, dot{dot2.x - d, dot2.y});
		vis[125 + dot2.x - d][125 + dot2.y] = 0;
jump4:
		printf("Found %d golygon(s).\n\n", cnt);
	}
}
