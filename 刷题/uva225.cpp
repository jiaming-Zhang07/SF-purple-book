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
set<dot>ob;
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
	int can[5];
	memset(can, -1, sizeof(can));
	for (auto x : ob) {
		if (x.y == dot2.y && dot2.x - x.x <= d && dot2.x - x.x >= 0 )
			can[2] = 0;
		if (x.x == dot2.x && dot2.y - x.y <= d && dot2.y - x.y >= 0)
			can[4] = 0;
		if (x.x == dot2.x && x.y - dot2.y <= d && x.y - dot2.y >= 0)
			can[1] = 0;
		if (x.y == dot2.y && x.x - dot2.x  <= d && x.x - dot2.x >= 0)
			can[3] = 0;
	}
	if (point == 1 || point == 4) {
		if (vis[125 + dot2.x + d][125 + dot2.y] || !can[3]) {
			goto jump;
		}
		c[d] = 3;
		vis[125 + dot2.x + d][125 + dot2.y] = 1;
		dfs(3, d + 1, dot{dot2.x + d, dot2.y});
		vis[125 + dot2.x + d][125 + dot2.y] = 0;
jump:
		if (vis[125 + dot2.x - d][125 + dot2.y] || !can[2])
			goto jump4;
		c[d] = 2;
		vis[125 + dot2.x - d][125 + dot2.y] = 1;
		dfs(2, d + 1, dot{dot2.x - d, dot2.y});
		vis[125 + dot2.x - d][125 + dot2.y] = 0;
jump4:
		;
	} else if (point == 2 || point == 3) {
		if (vis[125 + dot2.x][125 + dot2.y + d] || !can[1])
			goto jump2;
		c[d] = 1;
		vis[125 + dot2.x][125 + dot2.y + d] = 1;
		dfs(1, d + 1, dot{dot2.x, dot2.y + d});
		vis[125 + dot2.x][125 + dot2.y + d] = 0;
jump2:
		if (vis[125 + dot2.x][125 + dot2.y - d] || !can[4])
			goto jump3;
		c[d] = 4;
		vis[125 + dot2.x][125 + dot2.y - d] = 1;
		dfs(4, d + 1, dot{dot2.x, dot2.y - d});
		vis[125 + dot2.x][125 + dot2.y - d] = 0;
jump3:
		;
	}
}
int main() {

	int T;
	scanf("%d", &T);
	while (T--) {ob.clear();
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		int  m;
		scanf("%d%d", &maxl, &m);
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			ob.insert(dot{x, y});
		}
		dot dot2{0, 0 };
		int d = 1, can[5];
		memset(can, -1, sizeof(can));
		for (auto x : ob) {
			if (x.y == dot2.y && dot2.x - x.x <= d && dot2.x - x.x >= 0)
				can[2] = 0;
			if (x.x == dot2.x && dot2.y - x.y <= d && dot2.y - x.y >= 0)
				can[4] = 0;
			if (x.x == dot2.x && x.y - dot2.y <= d && x.y - dot2.y >= 0)
				can[1] = 0;
			if (x.y == dot2.y && x.x - dot2.x  <= d && x.x - dot2.x >= 0)
				can[3] = 0;
		}
		if (vis[125 + dot2.x + d][125 + dot2.y] || !can[3]) {
			goto jump;
		}
		c[d] = 3;
		vis[125 + dot2.x + d][125 + dot2.y] = 1;
		dfs(3, d + 1, dot{dot2.x + d, dot2.y});
		vis[125 + dot2.x + d][125 + dot2.y] = 0;
jump:
		if (vis[125 + dot2.x][125 + dot2.y + d] || !can[1]) {
			goto jump2;
		}
		c[d] = 1;
		vis[125 + dot2.x][125 + dot2.y + d] = 1;
		dfs(1, d + 1, dot{dot2.x, dot2.y + d});
		vis[125 + dot2.x][125 + dot2.y + d] = 0;
jump2:
		if (vis[125 + dot2.x][125 + dot2.y - d] || !can[4]) {
			goto jump3;
		}
		c[d] = 4;
		vis[125 + dot2.x][125 + dot2.y - d] = 1;
		dfs(4, d + 1, dot{dot2.x, dot2.y - d});
		vis[125 + dot2.x][125 + dot2.y - d] = 0;
jump3:
		if (vis[125 + dot2.x - d][125 + dot2.y] || !can[2]) {
			goto jump4;
		}
		c[d] = 2;
		vis[125 + dot2.x - d][125 + dot2.y] = 1;
		dfs(2, d + 1, dot{dot2.x - d, dot2.y});
		vis[125 + dot2.x - d][125 + dot2.y] = 0;
jump4:
		printf("Found %d golygon(s).\n\n", cnt);
	}
}
