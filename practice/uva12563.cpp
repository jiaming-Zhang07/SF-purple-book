#include <bits/stdc++.h>
using namespace std;
int len[55], d[2][180 * 55 + 678];
int main() {
  int T, n, t, kase = 0;
  cin >> T;
  while (T--) {
    int ans = 0;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
      cin >> len[i];
    for (int i = 1; i < t; i++)
      d[0][i] = -1;
    d[0][0] = 0;
    int p = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < t; j++) {
        d[p][j] = d[p ^ 1][j];
        if (j >= len[i] && d[p ^ 1][j - len[i]] >= 0)
          d[p][j] = max(d[p][j], d[p ^ 1][j - len[i]] + 1);
        ans = max(ans, d[p][j]);
      }
      p ^= 1;
    }
    for (int i = t - 1; i >= 0; i--)
      if (d[p ^ 1][i] == ans) {
        printf("Case %d: %d %d\n", ++kase, ans + 1, i + 678);
        break;
      }
  }
  return 0;
}