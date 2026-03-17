#include <bits/stdc++.h>
using namespace std;
int a[55], dp[55][55];
int main() {
  int l;
  while (cin >> l && l) {
    int n;
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    a[0] = 0;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    a[n + 1] = l;
    for (int i = 0; i < n + 1; i++)
      dp[i][1] = 0;
    for (int d = 2; d <= n + 1; d++)
      for (int i = 0; i < n + 2 - d; i++)
        for (int j = 1; j < d; j++)
          dp[i][d] = min(dp[i][d], a[i + d] - a[i] + dp[i][j] + dp[i + j][d - j]);
    cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
  }
  return 0;
}