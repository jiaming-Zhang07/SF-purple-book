#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll lef[105], righ[105], vl[105], vr[105], d[105][105][105][2];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int R = 1, L = 1;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      if (t > 0)
        righ[R++] = t;
      else
        lef[L++] = -t;
    }
    reverse(lef + 1, lef + L);
    ll ans = 0;
    memset(d, 0xcf, sizeof(d));
    for (int k = 1; k <= n; k++) {
      d[0][0][k][0] = d[0][0][k][1] = 0;
    }
    for (int i = L - 1; i > 0; i--)
      cin >> vl[i];
    for (int i = 1; i < R; i++)
      cin >> vr[i];
    for (int r = 0; r < R; r++)
      for (int l = 0; l < L; l++)
        for (int k = 1; k <= n - l - r; k++) {
          if (l < L - 1) {
            d[l + 1][r][k - 1][0] = max({d[l + 1][r][k - 1][0], d[l][r][k][1] + vl[l + 1] - k * (righ[r] + lef[l + 1]), d[l][r][k][0] + vl[l + 1] - k * (lef[l + 1] - lef[l])});
            if (k - 1 == 0)
              ans = max(ans, d[l + 1][r][k - 1][0]);
            d[l + 1][r][k][0] = max({d[l + 1][r][k][0], d[l][r][k][1] - k * (righ[r] + lef[l + 1]), d[l][r][k][0] - k * (lef[l + 1] - lef[l])});
          }
          if (r < R - 1) {
            d[l][r + 1][k - 1][1] = max({d[l][r + 1][k - 1][1], d[l][r][k][0] + vr[r + 1] - k * (righ[r + 1] + lef[l]), d[l][r][k][1] + vr[r + 1] - k * (righ[r + 1] - righ[r])});
            if (k - 1 == 0)
              ans = max(ans, d[l][r + 1][k - 1][1]);
            d[l][r + 1][k][1] = max({d[l][r + 1][k][1], d[l][r][k][0] - k * (righ[r + 1] + lef[l]), d[l][r][k][1] - k * (righ[r + 1] - righ[r])});
          }
        }
    cout << ans << "\n";
  }
  return 0;
}