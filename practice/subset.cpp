#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1000000007;
ll qpow(ll a, ll b, ll mod) {
  ll ans = 1;
  while (b > 0) {
    if (b & 1)
      ans = (ans * a) % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
ll C(ll n, ll k, ll mod) {
  if (k == 0 || k == n)
    return 1;
  if (k > n / 2)
    k = n - k;
  ll num = 1, den = 1;
  for (int i = 0; i < k; i++) {
    num = num * (n - i) % mod;
    den = den * (i + 1) % mod;
  }
  return num * qpow(den, mod - 2, mod) % mod;
}
int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  cout << (qpow(2, n, inf) - 1 - C(n, a, inf) - C(n, b, inf) + 3 * inf) % inf << "\n";
}