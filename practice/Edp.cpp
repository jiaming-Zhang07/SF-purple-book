#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll d[5005][105];
ll a[5005];
ll c[5005][105];
const ll mod = 998244353;
ll power(ll a, ll b, int mod) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = (res * a) % mod;
    b /= 2;
    a = (a * a) % mod;
  }
  return res;
}
ll inv[5005][105], inv2[5005][105];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  c[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  for (int i = 2; i <= n; i++)
    inv[i][0] = inv2[i][0] = 1;
  for (int i = 2; i <= n; i++) {
    ll t1 = power(i, mod - 2, mod), t2 = 1 - t1 + mod;
    for (int j = 1; j <= m; j++) {
      inv[i][j] = (inv[i][j - 1] * t1) % mod;
      inv2[i][j] = (inv2[i][j - 1] * t2) % mod;
    }
  }
  for (int j = 0; j <= m; j++)
    d[1][j] = (j >= 30) ? 0 : a[1] >> j;
  for (int i = 2; i <= n; i++)
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= j; k++)
        d[i][j] = (d[i][j] + c[j][k] * inv[i][k] % mod * inv2[i][j - k] % mod * ((k >= 30 ? 0 : a[i] >> k) + d[i - 1][j - k]) % mod) % mod;
  cout << d[n][m] << "\n";
  return 0;
}