#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n, k;
  while (cin >> n >> k && n) {
    ll i = 1, ans = 0;
    while (i <= n) {
      if (k / i == 0)
        break;
      ll m = k / (k / i);
      if (m > n)
        m = n;
      ans += (k % i + k % m) * (m - i + 1) / 2;
      i = m + 1;
    }
    ans += k * (n - i + 1);
    cout << ans << "\n";
  }
  return 0;
}