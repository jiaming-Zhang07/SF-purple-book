#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
ll m;
i128 C(ll n, int k) {
  i128 res = 1;
  for (int i = 1; i <= k; i++) {
    res = res * (n - i + 1) / i;
    if (res > m)
      return m + 1;
  }
  return res;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    vector<pair<ll, ll>> ans;
    cin >> m;
    for (int k = 1; k <= 30; k++) {
      if (C(2 * k, k) > m)
        break;
      ll l = 2 * k, r = m;
      while (l < r) {
        ll mid = l + (r - l) / 2;
        if (C(mid, k) < m)
          l = mid + 1;
        else
          r = mid;
      }
      if (C(l, k) == m) {
        ans.push_back({l, k});
        if (l - k != k)
          ans.push_back({l, l - k});
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x : ans)
      printf("(%lld,%lld)%c", x.first, x.second, x == ans.back() ? '\n' : ' ');
  }
  return 0;
}