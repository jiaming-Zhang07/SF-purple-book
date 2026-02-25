#include<bits/stdc++.h>
using namespace std;
int sta[10][10], maxn;
int n, m, vis[4][20];
bool dfs(int d,  int r, int c) {
	if (c == m) {
		r++;
		c = 0;
	}
	if (d == maxn) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (sta[i][j] && !vis[0][j] && !vis[1][j - i + 9] && !vis[2][j + i] && !vis[3][i])
					return false;
		return true;
	}
	if (r == n)
		return false;
	vis[0][c]++;
	vis[1][c - r + 9]++;
	vis[2][c + r]++;
	vis[3][r]++;
	if (dfs(d + 1, r, c + 1))
		return true;
	vis[0][c]-- ;
	vis[1][c - r + 9] --;
	vis[2][c + r] --;
	vis[3][r] --;
	if (dfs(d, r, c + 1))
		return true;
	return false;
}
int main() {
	
	int kase = 0;
	while (scanf("%d%d", &n, &m) == 2) {
		scanf(" ");
		memset(sta, 0, sizeof(sta));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) {
			char ch[20];
			fgets(ch, 20, stdin);
			for (int j = 0; j < m; j++)
				if (ch[j] == 'X')
					sta[i][j] = 1;
		}
		for (maxn = 1;; maxn++) {
			if (dfs(0,  0, 0))
				break;
		}
		printf("Case %d: %d\n", ++kase, maxn);
	}
}
