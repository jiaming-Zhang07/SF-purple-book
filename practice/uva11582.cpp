#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
ll power_mod(ll a, ll b, ll mod) {
  a %= mod;
  ll res = 1;
  while (b) {
    if (b & 1)
      res = (res * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return res;
}
int main() {
  int T;
  ll a, b, n;
  cin >> T;
  while (T--) {
    cin >> a >> b >> n;
    if (n == 1) {
      cout << "0\n";
      continue;
    }
    vector<int> f(2);
    f[0] = 0 % n, f[1] = 1 % n;
    int m, s = 0;
    for (int i = 2; i <= n * n; i++) {
      int t = (f[i - 2] + f[i - 1]) % n;
      if (f[i - 1] == 0 && t == 1) {
        m = i - 1;
        break;
      }
      f.push_back(t);
    }
    ll ans = 1;
    bool ok = false;
    for (ll i = 0; i < b; i++) {
      ans *= a;
      if (ans >= s) {
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << f[ans] << "\n";
      continue;
    }
    int pos = s + (power_mod(a, b, m) - s % m + m) % m;
    cout << f[pos] << "\n";
  }
  return 0;
}