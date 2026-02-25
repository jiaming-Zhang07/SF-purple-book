#include<bits/stdc++.h>
using namespace std;
/*    00    01
      02    03
04 05 06 07 08 09 10
	  11	12
13 14 15 16 17 18 19
	  20    21
	  22    23
*/
char ans[1000];
int c[8] = {6, 7, 8, 11, 12, 15, 16, 17};
int a[24];
int line[8][7] = {{0, 2, 6, 11, 15, 20, 22}, {1, 3, 8, 12, 17, 21, 23}, {10, 9, 8, 7, 6, 5, 4}, {19, 18, 17, 16, 15, 14, 13}};
int rev[8] = {5, 4, 7, 6, 1, 0, 3, 2};
bool fina() {
	for (int i = 1; i < 8; i++)
		if (a[c[i]] != a[c[0]])
			return false;
	return true;
}

void move(int n) {
	int t = a[line[n][0]];
	for (int i = 0; i < 6; i++)
		a[line[n][i]] = a[line[n][i + 1]];
	a[line[n][6]] = t;
}
int h() {
	int minh = 8;
	for (int k = 1; k <= 3; k++) {
		int cnt = 0;
		for (int i = 0; i < 8; i++)
			if (a[c[i]] != k)
				cnt++;
		minh = min(minh, cnt);
	}
	return minh;
}
bool dfs(int d, int maxd) {
	if (fina())
		{ans[d]='\0';
		return true;
	}
	if (d + h() > maxd)
		return false;
	for (int i = 0; i < 8; i++) {
		move(i);
	
		ans[d] = 'A' + i;
		if (dfs(d + 1, maxd))
			return true;

		move(rev[i]);
	}return false;
}
int main() {
	for (int i = 4; i < 8; i++)
		for (int j = 0; j < 7; j++)
			line[i][j] = line[rev[i]][6 - j];
	while (cin >> a[0] && a[0]) {
		for (int i = 1; i < 24; i++)
			cin >> a[i];
		if (fina())
			printf("No moves needed\n");
		else
			for (int maxd = 1;; maxd++)
				if (dfs(0, maxd)) {
					printf("%s\n", ans);
					break;
				}
		printf("%d\n", a[c[0]]);
	}
}
