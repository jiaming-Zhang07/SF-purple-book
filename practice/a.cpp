#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans = 0;
ll a[60];
ll n, dd, w;
int wei[60];
void dfs(ll sum, int i, int d, int maxd) {
  if (i + dd < n && (64 - __builtin_clzll(sum) > wei[i + dd] && 1ll << (64 - __builtin_clzll(sum) - 1) > w))
    return;
  if (d == maxd) {
    if (sum > w)
      return;
    ans++;
    return;
  }
  for (int j = i + dd; j < n; j++)
    if (maxd - d - 1 <= (n - j - 1) / dd)
      dfs(sum ^ a[j], j, d + 1, maxd);
}
int main() {
  cin >> n >> dd >> w;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = n - 1; i >= 0; i--) {
    int t = 64 - __builtin_clzll(a[i]);
    wei[i] = max(wei[i + 1], t);
  }
  for (int d = 1; d <= n; d++) {
    if (d > (n - 1) / dd + 1)
      break;
    for (int i = 0; i < n; i++) {
      if ((n - i - 1) / dd < d - 1)
        break;
      if ((d != 1 || a[i] <= w))
        dfs(a[i], i, 1, d);
    }
  }
  cout << ans;
  return 0;
}