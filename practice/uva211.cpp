#include<bits/stdc++.h>
using namespace std;
int G[7][7];
int a[7][8];
int vis[7][8], used[29];
int dx[] = {1, 0}, dy[] = {0, 1}, ans;
void print() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 8; j++)
			printf("%4d", vis[i][j]);
		printf("\n");
	}
	printf("\n");
}
void dfs(int x, int y, int d) {
	if (d == 28) {
		ans++;
		print();
		return;
	}
	if(y==8){x++;y=0;}
	if (vis[x][y])
		dfs(x, y + 1, d);
	else for (int i = 0; i < 2; i++) {
		int p = x + dx[i], q = y + dy[i];
		if(p>6||q>7)continue;
		if (used[G[a[x][y]][a[p][q]]] || vis[p][q])
			continue;
		used[G[a[x][y]][a[p][q]]] = 1;
		vis[x][y] = vis[p][q] = G[a[x][y]][a[p][q]];
		dfs(x, y + 1, d + 1);
		used[G[a[x][y]][a[p][q]]] = 0;
		vis[x][y] = vis[p][q] = 0;
	}
}
int main() {
	int bone = 1;
	for (int i = 0; i <= 6; i++)
		for (int j = i; j <= 6; j++) {
			G[i][j] = G[j][i] = bone++;
		}
	string s[7];
	int kase = 0;
	while (getline(cin, s[0])) {
		ans = 0;
		if (kase)
			printf("\n\n\n");
		printf("Layout #%d:\n\n", ++kase);
		for (int i = 1; i < 7; i++)
			getline(cin, s[i]);
		for (int i = 0; i < 7; i++) {
			stringstream ss(s[i]);
			for (int j = 0; j < 8; j++) {
				ss >> a[i][j];
				printf("%4d", a[i][j]);
			}
			printf("\n");
		}
		printf("\nMaps resulting from layout #%d are:\n\n", kase);
		dfs(0, 0, 0);
		printf("\nThere are %d solution(s) for layout #%d.\n", ans, kase);
	}
}
