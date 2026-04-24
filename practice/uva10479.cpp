#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int check(int k, ll pos) {
  if (k == 2)
    return 1;
  int t;
  bool ok = true;
  for (t = 1; t <= k - 3; t++)
    if (pos - t * (1ll << (k - t - 3)) >= 0)
      pos -= t * (1ll << (k - t - 3));
    else {
      ok = false;
      break;
    }
  if (ok) {
    if (pos == k - 2)
      return k - 1;
    else
      return 0;
  }
  return check(k - t - 1, pos % (1ll << (k - t - 3)));
}
int main() {
  ll n;
  while (cin >> n && n) {
    if (n == 1) {
      cout << 0 << "\n";
      continue;
    }
    int l = 0, r = 62;
    while (l < r) {
      int mid = l + (r - l - 1 + 2) / 2;
      if (n > 1ll << mid)
        l = mid;
      else
        r = mid - 1;
    }
    ll pos = n - (1ll << l) - 1, k = l + 2;
    cout << check(k, pos) << "\n";
  }
  return 0;
}