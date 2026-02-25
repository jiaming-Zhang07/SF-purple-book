#include<bits/stdc++.h>
using namespace std;
int g[15][15], used[15], num, n, s;
bool dfs(int m, int f) {
	used[m]=1;
	for (int i = 0; i < n; i++) {
		if (!g[m][i] || i == f || (s & 1 << i))
			continue;
		if (used[i])
			return 1;
		if (dfs(i, m))
			return 1;
	}
	return 0;
}
bool have_circle() {memset(used,0,sizeof(used));
	for (int i = 0; i < n; i++) {
		if (used[i] || (s & (1 << i)))
			continue;
		num++;
		if (dfs(i, -1))return 1;
		}return 0;
}
bool have_two() {
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		if (s & (1 << i))
			continue;
		for (int j = 0; j < n; j++) {
			if (g[i][j] && !(s & (1 << j)))
				cnt++;
			if (cnt > 2)
				return 1;
		}
	}return 0;
}
int cal(){int cnt=0;for(int i=0;i<n;i++)if(s&1<<i)cnt++;return cnt;}
int main() {int kase=0;
	while (scanf("%d", &n) == 1 && n) {memset(g,0,sizeof(g));
		int a, b;int ans=16;
		while (scanf("%d%d", &a, &b) == 2 && a != -1) {
			g[a - 1][b - 1] = g[b - 1][a - 1] = 1;
		}
		for ( s = 0; s < (1 << n); s++) {num=0;
			if (have_two() || have_circle())
				continue;
			int cn=cal();
			if(num-1>cn)continue;
			ans=min(ans,cn);
		}
		printf("Set %d: Minimum links to open is %d\n",++kase,ans);
	}
}
