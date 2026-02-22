#include<bits/stdc++.h>
using namespace std;
int en;
vector<int>G[22];
int last[22];
bool vis[22];
int cnt;
bool can[22];
void print(int t) {
	if (t == 1)
		printf("%d", t);
	else {
		print(last[t]);
		printf(" %d", t);
	}
}
void dfs2(int n) {
	if (n == 1)
		return;
	for (int i = 0; i < (int)G[n].size(); i++)
		if (!can[G[n][i]]) {
			can[G[n][i]] = true;
			dfs2(  G[n][i]);
		}
}
void dfs( int n) {
	if (n == en) {
		print(en);
		printf("\n");
		cnt++;
		return ;
	}
	for (int i = 0; i < (int)G[n].size(); i++)
		if (!vis[G[n][i]] && can[G[n][i]]) {
			last[G[n][i]] = n;
			vis[G[n][i]] = true;
			dfs(  G[n][i]);
			vis[G[n][i]] = false;
		}
}
int main() {
	int kase = 0;
	while (scanf("%d", &en) == 1) {
		cnt = 0;
		printf("CASE %d:\n", ++kase);
		for (int i = 0; i < 22; i++)
			G[i].clear();
		int a, b;
		while (scanf("%d%d", &a, &b) == 2 && a) {
			G[a].push_back(b);
			G[b].push_back(a);
		}
		memset(can, 0, sizeof(can));
		can[en] = true;
		dfs2(en);
		for (int i = 0; i < 22; i++)
			sort(G[i].begin(), G[i].end());
		vis[1] = true;
		dfs( 1);
		vis[1] = false;
		printf("There are %d routes from the firestation to streetcorner %d.\n", cnt, en);
	}
}
