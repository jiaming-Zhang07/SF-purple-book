#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
ll g[21][21], c[21][21], jie[20];
void init() {
  jie[0] = 1;
  for (int i = 1; i <= 19; i++) {
    jie[i] = jie[i - 1] * i;
  }
  for (int i = 0; i <= 20; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++)
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  g[0][0] = 1;
  for (int n = 1; n <= 20; n++)
    for (int m = 1; m <= n; m++)
      for (int k = 1; k <= n; k++)
        g[n][m] += c[n - 1][k - 1] * g[k - 1][m - 1] * jie[n - k];
}
int main() {
  int T;
  init();
  cin >> T;
  while (T--) {
    int n, l, r;
    cin >> n >> l >> r;
    ll ans = 0;
    for (int k = 1; k <= n; k++)
      ans += c[n - 1][k - 1] * g[k - 1][l - 1] * g[n - k][r - 1];
    cout << ans << "\n";
  }
  return 0;
}