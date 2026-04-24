#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  double t;
  while (cin >> n >> t && n) {
    double e = 1 << n;
    for (int k = n; k > 0; k--)
      if (1 << (k - 1) > t * e)
        e = (e * e + (1ll << (2 * k - 2)) - t * (1 << k) * e) / 2 / (1 - t) / e;
      else
        e = e * (1 + t) / 2;
    cout << fixed << setprecision(3) << e << "\n";
  }
  return 0;
}