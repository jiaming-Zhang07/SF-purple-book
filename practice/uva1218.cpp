#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
vector<int> g[maxn];
int n;
int d[maxn][3];
int dp(int i, int k, int v) {
  if (d[i][k] != -1)
    return d[i][k];
  d[i][0] = 1;
  d[i][1] = d[i][2] = 0;
  for (int x : g[i])
    if (x != v) {
      d[i][0] += min(dp(x, 1, i), dp(x, 0, i));
      d[i][1] += dp(x, 2, i);
    }
  int sum = d[i][1];
  d[i][2] = n;
  for (int x : g[i])
    if (x != v)
      d[i][2] = min(d[i][2], sum - d[x][2] + dp(x, 0, i));
  return d[i][k];
}
int main() {
  while (cin >> n && n != -1) {
    if (n == 0)
      continue;
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= n; i++)
      g[i].clear();
    for (int i = 0; i < n - 1; i++) {
      int a1, a2;
      cin >> a1 >> a2;
      g[a1].push_back(a2);
      g[a2].push_back(a1);
    }
    cout << min(dp(1, 0, -1), dp(1, 2, -1)) << "\n";
  }
  return 0;
}