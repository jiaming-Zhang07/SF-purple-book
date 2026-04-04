#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 505;
int a[maxn], maxc[maxn], cost[maxn][maxn];
int main() {
  int n;
  while (cin >> n) {
    memset(cost, 0x3f, sizeof(cost));
    vector<vector<bool>> is_perm(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
      int maxval = 0;
      vector<bool> seen(maxn, false);
      for (int j = i; j < n; j++) {
        if (seen[a[j]])
          break;
        seen[a[j]] = true;
        maxval = max(maxval, a[j]);
        if (maxval == j - i + 1)
          is_perm[i][j] = true;
      }
      vector<pair<int, int>> sorted;
      cost[i][i] = 0;
      sorted.push_back({a[i], i});
      for (int j = i + 1; j < n; j++) {
        int len = j - i + 1;
        pair<int, int> p = {a[j], j};
        auto it = lower_bound(sorted.begin(), sorted.end(), p);
        sorted.insert(it, p);
        int cur_min = sorted[0].second, cur_max = sorted[0].second;
        for (int m = 1; m < len; m++) {
          int pos = sorted[m].second;
          int next_min = min(pos, cur_min), next_max = max(pos, cur_max);
          for (int mid = next_min; mid < cur_min; mid++)
            maxc[mid] = m;
          for (int mid = cur_max; mid < next_max; mid++)
            maxc[mid] = m;
          cur_max = next_max;
          cur_min = next_min;
        }
        for (int mid = i; mid < j; mid++)
          cost[i][j] = min(cost[i][j], cost[i][mid] + cost[mid + 1][j] + len - maxc[mid]);
      }
    }
    vector<int> dp(n + 1, 1 << 30);
    dp[0] = 0;
    for (int j = 1; j <= n; j++)
      for (int i = 1; i <= j; i++)
        if (dp[i - 1] != 1 << 30 && is_perm[i - 1][j - 1])
          dp[j] = min(dp[j], dp[i - 1] + cost[i - 1][j - 1]);
    if (dp[n] == 1 << 30)
      cout << "impossible\n";
    else
      cout << dp[n] << "\n";
  }
  return 0;
}