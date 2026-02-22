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
	if (dot2.x == 0 && dot2.y == 0 ) {
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
	}if(d==maxl)vis[125][125]=0;
	if (point == 1 || point == 4) {
		if (can[3]) {
			int i;
			for ( i = 1; i <= d; i++) {
				if (vis[125 + dot2.x + i][125 + dot2.y])
					goto jump;
				vis[125 + dot2.x + i][125 + dot2.y] = 1;
			}
			c[d] = 3;
			dfs(3, d + 1, dot{dot2.x + d, dot2.y});
jump:
			for (int j = 1; j < i; j++)
				vis[125 + dot2.x + j][125 + dot2.y] = 0;
		}
		if (can[2]) {
			int i;
			for ( i = 1; i <= d; i++) {
				if (vis[125 + dot2.x - i][125 + dot2.y])
					goto jump4;
				vis[125 + dot2.x - i][125 + dot2.y] = 1;
			}
			c[d] = 2;
			dfs(2, d + 1, dot{dot2.x - d, dot2.y});
jump4:
			for (int j = 1; j < i; j++)
				vis[125 + dot2.x - j][125 + dot2.y] = 0;
		}
	} else if (point == 2 || point == 3) {
		if (can[1]) {
			int i;
			for ( i = 1; i <= d; i++) {
				if (vis[125 + dot2.x][125 + dot2.y + i])
					goto jump2;
				vis[125 + dot2.x][125 + dot2.y + i] = 1;
			}
			c[d] = 1;
			dfs(1, d + 1, dot{dot2.x, dot2.y + d});
jump2:
			for (int j = 1; j < i; j++)
				vis[125 + dot2.x][125 + dot2.y + j] = 0;
		}
		if (can[4]) {
			int i;
			for ( i = 1; i <= d; i++) {
				if (vis[125 + dot2.x][125 + dot2.y - i])
					goto jump3;
				vis[125 + dot2.x][125 + dot2.y - i] = 1;
			}
			c[d] = 4;
			dfs(4, d + 1, dot{dot2.x, dot2.y - d});
jump3:
			for (int j = 1; j < i; j++)
				vis[125 + dot2.x][125 + dot2.y - j] = 0;
		}
	}if(d==maxl)vis[125][125]=1;
}
int main() {
	freopen("z.txt", "r", stdin);
	freopen("zjm.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		cnt = 0;
		ob.clear();
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
		vis[125][125] = 1;
		if (can[3]) {
			int i;
			for ( i = 1; i <= d; i++) {
				if (vis[125 + dot2.x + i][125 + dot2.y])
					goto jump;
				vis[125 + dot2.x + i][125 + dot2.y] = 1;
			}
			c[d] = 3;
			dfs(3, d + 1, dot{dot2.x + d, dot2.y});
jump:
			for (int j = 1; j < i; j++)
				vis[125 + dot2.x + j][125 + dot2.y] = 0;
		}
		if (can[1]) {
			int i;
			for ( i = 1; i <= d; i++) {
				if (vis[125 + dot2.x][125 + dot2.y + i])
					goto jump2;
				vis[125 + dot2.x][125 + dot2.y + i] = 1;
			}
			c[d] = 1;
			dfs(1, d + 1, dot{dot2.x, dot2.y + d});
jump2:
			for (int j = 1; j < i; j++)
				vis[125 + dot2.x][125 + dot2.y + j] = 0;
		}
		if (can[4]) {
			int i;
			for ( i = 1; i <= d; i++) {
				if (vis[125 + dot2.x][125 + dot2.y - i])
					goto jump3;
				vis[125 + dot2.x][125 + dot2.y - i] = 1;
			}
			c[d] = 4;
			dfs(4, d + 1, dot{dot2.x, dot2.y - d});
jump3:
			for (int j = 1; j < i; j++)
				vis[125 + dot2.x][125 + dot2.y - j] = 0;
		}
		if (can[2]) {
			int i;
			for ( i = 1; i <= d; i++) {
				if (vis[125 + dot2.x - i][125 + dot2.y])
					goto jump4;
				vis[125 + dot2.x - i][125 + dot2.y] = 1;
			}
			c[d] = 2;
			dfs(2, d + 1, dot{dot2.x - d, dot2.y});
jump4:
			for (int j = 1; j < i; j++)
				vis[125 + dot2.x - j][125 + dot2.y] = 0;
		}
		printf("Found %d golygon(s).\n\n", cnt);
	}
}
