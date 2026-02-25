#include<bits/stdc++.h>
using namespace std;
struct sta {
	int used, post, d, idd;
}start ;
struct Move {
	int from, to;
} mov[520000];
int  vis[16][33000], fa[530000];
int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {memset(vis,0,sizeof(vis));memset(fa,-1,sizeof(fa));int ID=0;printf("Case %d: ",++kase);
		int n, m, s, t;start={0,0};
		scanf("%d%d%d%d", &n, &m, &s, &t);
		for (int i = 0; i < m; i++) {
			int t2;
			scanf("%d", &t2);
			start.used |= 1 << (t2 - 1);
		}
		vector<int>v[16];
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		start.used |= 1 << (s - 1);
		start.post = s;
		start.idd = ++ID;
		queue<sta>q;
		q.push(start);
		int ok=0;
		vis[start.post][start.used]=1;
		while (!q.empty()) {
			sta tmp = q.front();
			q.pop();
			if (tmp.post == t) {
				vector<Move>ans;
				printf("%d\n",  tmp.d);
				int t1 = tmp.idd;
				while (fa[t1] != -1) {
					ans.push_back(mov[t1]);
					t1 = fa[t1];
				}
				for (int i = ans.size()-1; i >=0; i--)
					printf("%d %d\n", ans[i].from, ans[i].to);
				printf("\n");ok=1;
				break;
			}
			for (int i = 1; i <= n; i++)
				if (tmp.used & 1 << (i - 1))
					for (int j = 0; j < (int)v[i].size(); j++)
						if (!(tmp.used & 1 << (v[i][j] - 1))) {
							sta tmp2 = tmp;
							tmp2.used &= ~(1 << (i - 1));
							tmp2.used |= 1 << (v[i][j] - 1);
							if (tmp2.post == i)
								tmp2.post = v[i][j];
							if (vis[tmp2.post][tmp2.used])
								continue;
							vis[tmp2.post][tmp2.used] = 1;
							fa[++ID] = tmp.idd;
							mov[ID] = Move{i, v[i][j]};
							tmp2.idd = ID;
							tmp2.d++;
							q.push(tmp2);
						}
		}if(!ok)printf("-1\n\n");
	}
}
