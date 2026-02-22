#include<bits/stdc++.h>
using namespace std;
int n, a[65], d[6] = {0, 3, 5, 7, 9, 11};
vector<int> h() {
	vector<int>ans;
	for (int s = 1; s <= n; s++)
		for (int i = 0; i + s <= n; i++)
			for (int j = 0; j + s <= n; j++) {
				bool ok = true;
				for (int k = i + j * d[n] + 1; k < i + j * d[n] + 1 + s; k++)
					if (!a[k] || !a[k + s * d[n]]) {
						ok = false;
						goto jump;
					}
				for (int k = i + n + 1 + j * d[n]; k < i + n + 1 + j * d[n] + s * d[n]; k += d[n])
					if (!a[k] || !a[k + s]) {
						ok = false;
						goto jump;
					}
jump:
				if (ok) {
					for (int k = i + j * d[n] + 1; k < i + j * d[n] + 1 + s; k++) {
						ans.push_back(k);
						ans.push_back(k + s*d[n]);
					}
					for (int k = i + n + 1 + j * d[n]; k < i + n + 1 + j * d[n] + s * d[n]; k += d[n]) {
						ans.push_back(k);
						ans.push_back(k + s);
					}
					return ans;
				}
			}return ans;
}
bool dfs(int d, int maxd) {
	vector<int> target = h();
	if (target.empty())
		return true;
	if ( d  ==  maxd )
		return false;
	for (int i = 0; i < (int)target.size(); i++) {
		a[target[i]] = 0;
		if (dfs(d + 1, maxd))
			return true;
		a[target[i]] = -1;
	}
	return false;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int k;
		scanf("%d%d", &n, &k);
		memset(a, -1, sizeof(a));
		for (int i = 0; i < k; i++) {
			int t;
			scanf("%d", &t);
			a[t] = 0;
		}
		int maxd;
		for ( maxd = 0;; maxd++)
			if (dfs(0, maxd))
				break;
		printf("%d\n", maxd);
	}
}
