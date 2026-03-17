#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
int n;
double dist[maxn][maxn], d[1 << maxn][maxn];
double dfs(int vis, int u) {
  if (vis == (1 << n) - 1)
    return dist[u][0];
  if (d[vis][u] > 0)
    return d[vis][u];
  d[vis][u] = 1e15;
  for (int i = 0; i < n; i++)
    if (!(vis & 1 << i))
      d[vis][u] = min(d[vis][u], dist[u][i] + dfs(vis | (1 << i), i));
  return d[vis][u];
}
int main() {
  cin >> n;
  double ans = dfs(1, 0);
  printf("%.2f\n", ans);
  return 0;
}