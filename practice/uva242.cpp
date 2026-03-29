#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1005, INF = 1 << 30;
vector<int> ans;
int maxlen = 0;
int dp[maxn];
bool is_better(const vector<int> &v, int t) {
  if (maxlen != t)
    return maxlen < t;
  if (ans.size() != v.size())
    return ans.size() > v.size();
  for (int i = (int)ans.size() - 1; i >= 0; i--)
    if (ans[i] != v[i])
      return ans[i] > v[i];
  return false;
}
int main() {
  int s, n, m;
  while (cin >> s && s) {
    maxlen = -1;
    ans.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> m;
      vector<int> v(m);
      for (int j = 0; j < m; j++)
        cin >> v[j];
      fill(dp, dp + maxn, INF);
      dp[0] = 0;
      for (int val : v)
        for (int k = val; k < maxn; k++)
          if (dp[k - val] < s)
            dp[k] = min(dp[k], dp[k - val] + 1);
      int t = 0;
      while (dp[t + 1] != INF)
        t++;
      if (is_better(v, t)) {
        ans = v;
        maxlen = t;
      }
    }
    printf("max coverage = %3d :", maxlen);
    for (int v : ans)
      printf("%3d", v);
    printf("\n");
  }
  return 0;
}