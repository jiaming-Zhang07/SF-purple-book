#include<bits/stdc++.h>
using namespace std;
struct cell {
	int t, f, l;
};
cell a[3][3];
int sta[3][3];
int ans[3][3], maxd;
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
bool dfs(int r, int c, int d, int ban) {int nban;
	if (d == maxd) {
		sta[r][c] = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (sta[i][j] != ans[i][j])
					return false;
		return true;
	}
	for (int i = 0; i < 4; i++)
		if (i != ban && r + dr[i] >= 0 && r + dr[i] < 3 && c + dc[i] >= 0 && c + dc[i] < 3) {
			cell t = a[r + dr[i]][c + dc[i]];
			switch (i) {
				case 0:
					nban = 1;
					a[r][c] = cell{t.f, t.t, t.l};
					sta[r][c] = t.f;
					break;
				case 1:
					nban = 0;
					a[r][c] = cell{t.f, t.t, t.l};
					sta[r][c] = t.f;
					break;
				case 2:
					nban = 3;
					a[r][c] = cell{t.l, t.f, t.t};
					sta[r][c] = t.l;
					break;
				case 3:
					nban = 2;
					a[r][c] = cell{t.l, t.f, t.t};
					sta[r][c] = t.l;
					break;
			}
			if (dfs(r + dr[i], c + dc[i], d + 1, nban))
				return true;
		}return false;
}
int main() {
	int r, c;
	while (scanf("%d%d", &c, &r) == 2 && c) {
		r--, c--;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				char t;
				while(scanf("%c", &t)==1&&!isalpha(t));
				switch (t) {
					case'E':ans[i][j]=0;break;case 'W':ans[i][j]=1;break;case'R':ans[i][j]=2;break;case 'B':ans[i][j]=3;break;}
						}
				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
						if (i != r && j != c) {
							sta[i][j] = 1;
							a[i][j] = cell{1, 2, 3};
						}
				sta[r][c] = 0;
				for (maxd = 0; maxd <= 30; maxd++)
					if (dfs(r, c, 0, 5))
						break;
				if (maxd == 31)
					printf("-1\n");
				else
					printf("%d\n", maxd);
			}
	}
