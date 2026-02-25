#include<bits/stdc++.h>
using namespace std;
int  a[10], n, maxn;

int h() {
	int cnt = 0;
	for (int i = 0; i < n - 1; i++)
		if (a[i] + 1 != a[i + 1])
			cnt++;
	if (a[n - 1] != n)
		cnt++;
	return cnt;
}
bool is_sort() {
	for (int i = 0; i < n; i++)
		if (a[i] != i + 1)
			return false;
	return true;
}
bool dfs(int d) {
	if (d * 3 + h() > maxn * 3)
		return false;
	if (is_sort())
		return true;
	int olda[10];
	memcpy(olda, a, sizeof(a));
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			int cnt = 0, b[10];
			for (int k = 0; k < n; k++)
				if (k < i || k > j)
					b[cnt++] = olda[k];
			for (int k = 0; k <= cnt; k++) {
				int cnt2 = 0;
				for (int p = 0; p < k; p++)
					a[cnt2++] = b[p];
				for (int p = i; p <= j; p++)
					a[cnt2++] = olda[p];
				for (int p = k; p < cnt; p++)
					a[cnt2++] = b[p];
				if (dfs(d + 1)) {
					return true;
				}
			}
		}
	memcpy(a, olda, sizeof(a));
	return false;
}
int main() {
	int kase = 0;
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (maxn = 0; maxn < 5; maxn++) {
			if (dfs(0))
				break;
		}
		printf("Case %d: %d\n", ++kase, maxn);
	}
}
