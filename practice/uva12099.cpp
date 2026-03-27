#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 75, maxw = 35;
struct book {
  int h, w;
  bool operator<(const book &other) const {
    return h > other.h;
  }
} b[maxn];
int dp[2][maxn * maxw][maxn * maxw], sumw[maxn];
int f(int j, int h) {
  return j == 0 ? h : 0;
}
void update(int &a, int b) {
  if (a < 0 || b < a)
    a = b;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> b[i].h >> b[i].w;
    sort(b, b + n);
    for (int i = 1; i <= n; i++)
      sumw[i] = sumw[i - 1] + b[i - 1].w;
    int t = 0;
    memset(dp[0], -1, sizeof(dp[0]));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= sumw[i + 1]; j++)
        for (int k = 0; k <= sumw[i + 1] - j; k++)
          dp[t ^ 1][j][k] = -1;
      for (int j = 0; j <= sumw[i]; j++)
        for (int k = 0; k <= sumw[i] - j; k++)
          if (dp[t][j][k] >= 0) {
            update(dp[t ^ 1][j][k], dp[t][j][k]);
            update(dp[t ^ 1][j + b[i].w][k], dp[t][j][k] + f(j, b[i].h));
            update(dp[t ^ 1][j][k + b[i].w], dp[t][j][k] + f(k, b[i].h));
          }
      t ^= 1;
    }
    int ans = 1 << 30;
    for (int j = 1; j <= sumw[n]; j++)
      for (int k = 1; k <= sumw[n] - j; k++)
        if (dp[t][j][k] >= 0) {
          ans = min(ans, (dp[t][j][k] + b[0].h) * max({j, k, sumw[n] - j - k}));
        }
    cout << ans << "\n";
  }
  return 0;
}