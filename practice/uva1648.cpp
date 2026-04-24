#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n, m;
  while (cin >> n >> m) {
    ll ans = 1ll << 60;
    for (int i = 0; i < m; i++) {
      ll u, d;
      cin >> u >> d;
      ans = min(ans, (n * d / (u + d) + 1) * (u + d) - n * d);
    }
    cout << ans << "\n";
  }
  return 0;
}