#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll h[105], x[20005], dp[2][20005];
const ll INF = 1ll << 60;
int main() {
  int T;
  cin >> T;
  while (T--) {
    ll n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
      cin >> h[i];
    if (abs(h[n - 1] - h[0]) > (n - 1) * d) {
      cout << "impossible\n";
      continue;
    }
    int nx = 0;
    for (int i = 0; i < n; i++)
      for (int j = -n + 1; j <= n - 1; j++)
        x[nx++] = h[i] + j * d;
    sort(x, x + nx);
    nx = unique(x, x + nx) - x;
    int t = 0;
    for (int i = 0; i < nx; i++) {
      dp[0][i] = INF;
      if (x[i] == h[0])
        dp[0][i] = 0;
    }
    for (int i = 1; i < n; i++) {
      int k = 0;
      for (int j = 0; j < nx; j++) {
        while (k < nx && x[k] < x[j] - d)
          k++;
        while (k + 1 < nx && x[k + 1] <= x[j] + d && dp[t][k + 1] <= dp[t][k])
          k++;
        if (dp[t][k] == INF)
          dp[t ^ 1][j] = INF;
        else
          dp[t ^ 1][j] = dp[t][k] + abs(x[j] - h[i]);
      }
      t ^= 1;
    }
    for (int i = 0; i < nx; i++)
      if (x[i] == h[n - 1]) {
        cout << dp[t][i] << "\n";
        break;
      }
  }
  return 0;
}