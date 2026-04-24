#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T, kase = 0;
  cin >> T;
  while (T--) {
    ll a, b;
    cin >> a >> b;
    int res = -1;
    for (ll s = 4; s <= 10000 - 1 + 4; s++)
      if (2 * a * s <= (3 * a - b) * (s / 2) * (s - s / 2)) {
        res = s - 3;
        break;
      }
    cout << "Case " << ++kase << ": " << res << "\n";
  }
  return 0;
}