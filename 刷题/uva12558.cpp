#include<bits/stdc++.h>
using namespace std;
using ll = long long;
set<ll>s;
ll ans[100000], best[100000];
ll maxn;
ll h(ll a, ll b) {
	return b / a + 1;
}
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
bool dfs(ll n, ll from, ll a, ll b) {
	int ok = 0;
	if (n == maxn - 1) {
		if (b % a == 0 && !s.count(b / a) && b / a >= from) {
			ans[maxn - 1] = b / a;
			for (int i = maxn - 1; i >= 0; i--) {
				if (ans[i] < best[i] || best[i] == 0) {
					memcpy(best, ans, sizeof(ans));
					break;
				}
				if (ans[i] > best[i])
					break;
			}
			return true;
		}
		return false;
	}
	from = max(h(a, b), from);
	while (s.count(from))
		from++;
	for (ll i = from;; i++) {if(s.count(i))continue;
		if (b * (maxn - n) <= a * i)
			break;
		ans[n] = i;
		ll g = gcd(a*i - b, b*i);
		if (dfs(n + 1, i + 1, (a * i - b) / g, b * i / g))
			ok = 1;
	}
	if (ok)
		return true;
	return false;
}
int main() {
	int T, kase = 0;
	cin >> T;
	while (T--) {
		memset(best, 0, sizeof(best));
		printf("Case %d: ", ++kase);
		s.clear();
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		for (int i = 0; i < k; i++) {
			int t;
			scanf("%d", &t);
			s.insert(t);
		}
		for (maxn = 1;; maxn++ )
			if (dfs(0, 2, a, b))
				break;
		printf("%d/%d=", a, b);
		for (int i = 0; i < maxn; i++)
			printf("1/%lld%c", best[i], i == maxn - 1 ? '\n' : '+');
	}
}
