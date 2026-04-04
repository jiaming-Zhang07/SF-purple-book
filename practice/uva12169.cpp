#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 10001;
int x[105];
int exgcd(int a, int b, int &d, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    d = a;
    return a;
  }
  exgcd(b, a % b, d, y, x);
  y -= a / b * x;
  return d;
}
signed main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++)
    cin >> x[i];
  if (T == 1) {
    cout << x[0] << "\n";
    return 0;
  }
  int b0, n, d;
  for (int a = 0; a <= 10005; a++) {
    int c = ((x[1] - a * a * x[0]) % mod + mod) % mod;
    if (c % exgcd(a + 1, mod, d, b0, n) == 0) {
      b0 *= c / d;
      int step = mod / d;
      b0 = (b0 % step + step) % step;
      for (int k = 0; k < d; k++) {
        int b = b0 + k * step;
        bool ok = true;
        for (int i = 2; i < T; i++) {
          if ((a * ((a * x[i - 1] + b)) + b) % mod != x[i]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          for (int i = 0; i < T; i++) {
            cout << (a * x[i] + b) % mod << "\n";
          }
          return 0;
        }
      }
    }
  }
  return 0;
}