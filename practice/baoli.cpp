#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
ll sum[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ll t;
    cin >> t;
    sum[i] = sum[i - 1] + t;
  }
  ll ans = 0;
  tuple<int, int, int> an;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int k = j + 1; k <= n; k++)
        if (ans < abs(sum[i]) + abs(sum[j] - sum[i]) + abs(sum[k] - sum[j]) + abs(sum[n] - sum[k])) {
          ans = abs(sum[i]) + abs(sum[j] - sum[i]) + abs(sum[k] - sum[j]) + abs(sum[n] - sum[k]);
          an = {i, j, k};
        }
  auto [i, j, k] = an;
  cout << ans << "\n" << i << " " << j << " " << k;
  return 0;
}
// 30
// 1 4 5