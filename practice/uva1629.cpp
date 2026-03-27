#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 25, INF = 1 << 30;
int cnt[maxn][maxn], d[maxn][maxn][maxn][maxn];
int dp(int r, int c, int n, int m) {
  int t = cnt[r + n - 1][c + m - 1] - cnt[r + n - 1][c - 1] - cnt[r - 1][c + m - 1] + cnt[r - 1][c - 1];
  if (t == 0)
    return INF;
  if (t == 1)
    return 0;
  int &ans = d[r][c][n][m];
  if (ans)
    return ans;
  ans = INF;
  for (int i = 0; i < n - 1; i++)
    ans = min(ans, m + dp(r, c, i + 1, m) + dp(r + i + 1, c, n - i - 1, m));
  for (int i = 0; i < m - 1; i++)
    ans = min(ans, n + dp(r, c, n, i + 1) + dp(r, c + i + 1, n, m - 1 - i));
  return ans;
}
int main() {
  int n, m, k, kase = 0;
  while (cin >> n >> m >> k) {
    memset(d, 0, sizeof(d));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < k; i++) {
      int r, c;
      cin >> r >> c;
      cnt[r][c]++;
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
    printf("Case %d: %d\n", ++kase, dp(1, 1, n, m));
  }
  return 0;
}