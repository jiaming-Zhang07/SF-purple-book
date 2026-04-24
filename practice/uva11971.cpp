#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}
int main() {
  int n, k, T, kase = 0;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    ll num = (1ll << k) - k - 1, den = 1ll << k, g = gcd(num, den);
    printf("Case #%d: %lld/%lld\n", ++kase, num / g, den / g);
  }
  return 0;
}