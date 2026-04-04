#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5005;
ll a[maxn], d[maxn][2];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    reverse(a, a + n);
    memset(d, 0x3f, sizeof(d));
    for (int j = 0; j < n; j++)
      d[j][0] = 0;
    int t = 0;
    for (int m = 1; m <= k + 8; m++) {
      t ^= 1;
      for (int i = 0; i < n; i++)
        d[i][t] = 1ll << 60;
      for (int i = 3 * m - 1; i < n; i++) {
        d[i][t] = min(d[i - 1][t], d[i - 2][t ^ 1] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]));
      }
    }
    cout << d[n - 1][t] << "\n";
  }
  return 0;
}