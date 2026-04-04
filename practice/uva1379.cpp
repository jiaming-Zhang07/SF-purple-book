#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int sche[10005], top[1005][10], id[1005][10];
int dp[2][10][10][10][10];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, g;
    cin >> n >> m >> g;
    int upp = min(n + 1, 10);
    for (int i = 1; i <= m; i++) {
      vector<pair<int, int>> v(n);
      for (int j = 1; j <= n; j++) {
        cin >> v[j - 1].first;
        v[j - 1].second = j;
      }
      sort(v.rbegin(), v.rend());
      for (int j = 1; j < upp; j++) {
        top[i][j] = v[j - 1].first;
        id[i][j] = v[j - 1].second;
      }
    }
    for (int i = 0; i < g + 10; i++)
      cin >> sche[i];
    int t = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = g + 9; i >= 0; i--) {
      t ^= 1;
      for (int a = 0; a < upp; a++)
        for (int b = 0; b < upp; b++)
          for (int c = 0; c < upp; c++)
            for (int d = 0; d < upp; d++) {
              dp[t][a][b][c][d] = -(1 << 30);
              int p[5];
              p[1] = i - 4 >= 0 ? id[sche[i - 4]][a] : 0, p[2] = i - 3 >= 0 ? id[sche[i - 3]][b] : 0, p[3] = i - 2 >= 0 ? id[sche[i - 2]][c] : 0, p[4] = i - 1 >= 0 ? id[sche[i - 1]][d] : 0;
              if ((p[1] && (p[1] == p[2] || p[1] == p[3] || p[1] == p[4])) || (p[2] && (p[2] == p[3] || p[2] == p[4])) || (p[3] && (p[3] == p[4]))) {
                continue;
              }
              if (sche[i] == 0) {
                dp[t][a][b][c][d] = dp[t ^ 1][b][c][d][0];
                continue;
              }
              for (int j = 1; j < upp; j++) {
                if (id[sche[i]][j] == p[1] || id[sche[i]][j] == p[2] || id[sche[i]][j] == p[3] || id[sche[i]][j] == p[4])
                  continue;
                dp[t][a][b][c][d] = max(dp[t][a][b][c][d], dp[t ^ 1][b][c][d][j] + top[sche[i]][j]);
              }
            }
    }
    int ans = dp[t][0][0][0][0];
    printf("%.2f\n", ans / 100.0 + 1e-9);
  }
  return 0;
}