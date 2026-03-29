#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
ll ans[405][13], d[405][1 << 12];
bool is_palin(int m, int n) {
  int l = n - 1;
  for (int i = 0; i < n / 2; i++)
    if (((m >> (l - i) ^ m >> i) & 1) != 0)
      return false;
  return true;
}
void init() {
  for (int k = 1; k <= 12; k++) {
    memset(d, 0, sizeof(d));
    for (int n = 1; n < 405; n++)
      if (k > n)
        ans[n][k] = 1 << n;
      else if (k == n) {
        for (int m = 0; m < (1 << k); m++)
          if (!is_palin(m, n)) {
            d[n][m] = 1;
            ans[n][k]++;
          } else
            d[n][m] = 0;
      } else {
        for (int m = 0; m < 1 << k; m++)
          if (d[n - 1][m]) {
            for (int i = 0; i < 2; i++) {
              if (is_palin(m << 1 | i, k + 1))
                continue;
              if (is_palin(m << 1 | i, k))
                continue;
              int nm = (m << 1 | i) & (1 << k) - 1;
              d[n][nm] = (d[n][nm] + d[n - 1][m]) % mod;
            }
          }
        for (int m = 0; m < 1 << k; m++)
          ans[n][k] = (ans[n][k] + d[n][m]) % mod;
      }
  }
}
int main() {
  init();
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    cout << ans[n][k] << "\n";
  }
  return 0;
}