#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1005, mod = 1e9 + 7;
int a[maxn][maxn], b[maxn][maxn], t[maxn][maxn], d[maxn][maxn];
ll ans;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> a[i][j];
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++)
      cin >> b[i][j];
  for (int k = 0; k <= 29; k++) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        t[i][j] = a[i][j] >> k & 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        d[i][j] = t[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= m; j++) {
        ll cnt = d[n - m + i][n - m + j] - d[i - 1][n - m + j] - d[n - m + i][j - 1] + d[i - 1][j - 1];
        if (b[i][j] >> k & 1)
          cnt = (n - m + 1) * (n - m + 1) - cnt;
        ans = (ans + cnt * (1 << k)) % mod;
      }
  }
  cout << ans << "\n";
  return 0;
}