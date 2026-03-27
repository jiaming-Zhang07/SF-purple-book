#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1000005;
const int mod = 998244353;
ll a[maxn];
int main() {
  int n, p;
  ll cnt = 0;
  cin >> n >> p;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans = (ans + a[i]) % mod;
    ll v = a[i];
    ll t = 0;
    while ((-v & v) != v) {
      v += -v & v;
      t++;
    }
    cnt = max(cnt, t);
  }
  int cnto = 0;
  while (p--) {
    int o;
    cin >> o;
    if (o == 1) {
      if (cnto < cnt) {
        for (int i = 0; i < n; i++) {
          ans = (ans + ((~a[i]) + 1 & a[i])) % mod;
          a[i] += (~a[i]) + 1 & a[i];
        }
        cnto++;
      } else {
        ans = (2 * ans) % mod;
      }
    } else {
      cout << ans << "\n";
    }
  }
  return 0;
}