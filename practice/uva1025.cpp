#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
int t[55], dp[205][55];
bool has_train[205][55][2];
int main() {
  int n, T, kase = 0;
  while (cin >> n >> T && n) {
    memset(has_train, 0, sizeof(has_train));
    cout << "Case Number " << ++kase << ": ";
    for (int i = 1; i <= n - 1; i++)
      cin >> t[i];
    int M1;
    cin >> M1;
    for (int i = 0; i < M1; i++) {
      int tt;
      cin >> tt;
      if (tt <= T)
        has_train[tt][1][1] = true;
      for (int i = 1; i <= n - 2; i++) {
        tt += t[i];
        if (tt <= T)
          has_train[tt][i + 1][1] = true;
      }
    }
    int M2;
    cin >> M2;
    for (int i = 0; i < M2; i++) {
      int tt;
      cin >> tt;
      if (tt <= T)
        has_train[tt][n][0] = true;
      for (int i = n - 1; i >= 2; i--) {
        tt += t[i];
        if (tt <= T)
          has_train[tt][i][0] = true;
      }
    }
    for (int i = 1; i < n; i++)
      dp[T][i] = INF;
    dp[T][n] = 0;
    for (int i = T - 1; i >= 0; i--)
      for (int j = 1; j <= n; j++) {
        dp[i][j] = dp[i + 1][j] + 1;
        if (has_train[i][j][1] && i + t[j] <= T)
          dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);
        if (has_train[i][j][0] && i + t[j - 1] <= T)
          dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]);
      }
    if (dp[0][1] >= INF)
      cout << "impossible\n";
    else
      cout << dp[0][1] << "\n";
  }
  return 0;
}