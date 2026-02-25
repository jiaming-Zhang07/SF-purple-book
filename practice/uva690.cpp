#include<bits/stdc++.h>
using namespace std;
int sum0[5];
int n, ans, mint;
vector<int>cant;
void dfs(int* sum, int cnt, int num) {
	if (cnt + (10 - num ) * mint >= ans)
		return;
	if (num == 10) {
		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < (int) cant.size(); i++) {
		int ok = 1;
		int t = cant[i];
		for (int j = 0; j < 5; j++)
			if (sum0[j] &sum[j] << t) {
				ok = 0;
				break;
			}
		int next_sum[5];
		if (ok) {
			for (int j = 0; j < 5; j++) {
				next_sum[j] = (sum0[j] + (sum[j] << t)) & (1 << 20) - 1;
			}
			dfs(next_sum, cnt + t, num + 1);
		}
	}
}
int main() {
	while (scanf("%d", &n) == 1 && n) {cant.clear();
		ans = 300;
		memset(sum0, 0, sizeof(sum0));
		string s;
		for (int i = 0; i < 5; i++) {
			cin >> s;
			for (int j = 0; j < n; j++) {
				if (s[j] == 'X')
					sum0[i] += (1 << (n - 1 - j));
			}
		}
		for (int t = 1; t <= n; t++) {
			int ok = 1;
			for (int i = 0; i < 5; i++)
				if (sum0[i]&sum0[i] << t) {
					ok = 0;
					break;
				}
			if (ok)
				cant.push_back(t);
		}
		mint = cant[0];
		dfs(sum0, n, 1);
		printf("%d\n", ans);
	}
}
