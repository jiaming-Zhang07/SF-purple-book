#include<bits/stdc++.h>
using namespace std;
using  LL = long long;
LL maxn, a, b, ans[100], v[100];
LL get_first(LL aa, LL bb) {
	return bb / aa + 1;
}
bool better(int d) {
	for (int i = d; i >= 0; i--)
		if (ans[i] != v[i])
			return ans[i] > v[i] || ans[i] == -1;
	return false;
}
bool dfs(int d, LL from, LL aa, LL bb) {
	bool ok = false;
	if (d == maxn) {
		if (bb % aa)
			return false;
		v[d] = bb / aa;
		if (better(d))
			memcpy(ans, v, sizeof(LL) * (d + 1));
		return true;
	}
	for (from = max(from, get_first(aa, bb));; from++) {
		if ((maxn - d + 1) * bb <= aa * from)
			break;
		v[d] = from;
		LL aa2 = aa*from - bb, bb2 = bb*from, g = gcd(aa2, bb2);
		if (dfs(d + 1, from + 1, aa2 / g, bb2 / g))
			ok = true;
	}
	return ok;
}
int main() {
	int kase = 0;
	while (cin >> a >> b) {
		memset(ans, -1, sizeof(ans));
		int ok = 0;
		for (maxn = 1; maxn <= 100; maxn++) {
			if (dfs(0, get_first(a, b), a, b)) {
				ok = 1;
				break;
			}
		}
		if (ok) {
			printf("Case %d:", ++kase);
			for (int i = 0; i < maxn; i++)
				printf("1/%lld+", ans[i]);
			printf("1/%lld", ans[maxn]);
		}
	}
}
