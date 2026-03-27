#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct wall {
  int x, c, d;
  bool operator<(const wall &other) const {
    return x < other.x;
  }
};
double dp[1005][1005][2];
wall a[1005];
double sum[1005];
int main() {
  int n, x;
  double v;
  while (cin >> n >> v >> x && n) {
    for (int i = 1; i <= n + 1; i++)
      for (int j = i; j <= n + 1; j++)
        dp[i][j][0] = dp[i][j][1] = 1e15;
    int lef = 0, righ = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].x >> a[i].c >> a[i].d;
      if (a[i].x < x)
        lef++;
      else
        righ++;
    }
    a[n + 1] = {x};
    sort(a + 1, a + n + 2);
    for (int i = 1; i <= n + 1; i++) {
      sum[i] = sum[i - 1] + a[i].d;
    }
    int st = lef + 1;
    dp[st][st][0] = dp[st][st][1] = 0;
    n++;
    for (int i = 0; i <= lef; i++)
      for (int j = 0; j <= righ; j++) {
        int l = st - i, r = st + j;
        if (l > 1)
          dp[l - 1][r][0] = min({dp[l][r][0] + (sum[l - 1] + sum[n] - sum[r]) * (a[l].x - a[l - 1].x) / v + a[l - 1].c, dp[l][r][1] + (sum[l - 1] + sum[n] - sum[r]) * (a[r].x - a[l - 1].x) / v + a[l - 1].c, dp[l - 1][r][0]});
        if (r < n)
          dp[l][r + 1][1] = min({dp[l][r][0] + (sum[l - 1] + sum[n] - sum[r]) * (a[r + 1].x - a[l].x) / v + a[r + 1].c, dp[l][r][1] + (sum[l - 1] + sum[n] - sum[r]) * (a[r + 1].x - a[r].x) / v + a[r + 1].c, dp[l][r + 1][1]});
      }
    cout << (int)min(dp[1][n][0], dp[1][n][1]) << "\n";
  }
  return 0;
}