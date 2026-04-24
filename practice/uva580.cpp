#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int f[35], g[35];
int main() {
  int n;
  f[0] = f[1] = f[2] = 0;
  f[3] = 1;
  g[0] = 1;
  g[1] = 2;
  g[2] = 4;
  g[3] = 7;
  for (int i = 4; i <= 30; i++) {
    f[i] = 2 * f[i - 1] + g[i - 4];
    g[i] = (1 << i) - f[i];
  }
  while (cin >> n && n) {
    cout << f[n] << "\n";
  }
  return 0;
}