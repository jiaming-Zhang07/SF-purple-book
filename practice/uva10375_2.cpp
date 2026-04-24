#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int p, q, r, s;
  while (cin >> p >> q >> r >> s) {
    q = min(q, p - q);
    s = min(s, r - s);
    double ans = 1;
    for (int i = 1; i <= q || i <= s; i++) {
      if (i <= q)
        ans *= (double)(p + 1 - i) / i;
      if (i <= s)
        ans *= (double)i / (r + 1 - i);
    }
    cout << fixed << setprecision(5) << ans << "\n";
  }
  return 0;
}