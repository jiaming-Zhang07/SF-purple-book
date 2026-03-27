#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 45;
int cnt[maxn][maxn][maxn][maxn], a[maxn][5];
int n;
int dp(int i, int j, int k, int m, int mask) {
  if (__builtin_popcount(mask) >= 5)
    return 0;
  int &ans = cnt[i][j][k][m];
  if (ans != -1)
    return ans;
  ans = 0;
  int t[] = {i, j, k, m};
  for (int d = 0; d < 4; d++)
    if (t[d] < n) {
      int color = a[t[d]][d];
      t[d]++;
      if (1 << color & mask)
        ans = max(ans, 1 + dp(t[0], t[1], t[2], t[3], mask ^ 1 << color));
      else
        ans = max(ans, dp(t[0], t[1], t[2], t[3], mask | 1 << color));
      t[d]--;
    }
  return ans;
}
int main() {
  while (cin >> n && n) {
    memset(cnt, -1, sizeof(cnt));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 4; j++)
        cin >> a[i][j];
    cout << dp(0, 0, 0, 0, 0) << "\n";
  }
  return 0;
}