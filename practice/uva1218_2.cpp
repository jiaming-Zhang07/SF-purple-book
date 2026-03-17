#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005, INF = 1 << 29;
vector<int> g[maxn];
int n;
int d[maxn][3], f[maxn];
vector<int> order;
void dfs(int u, int v) {
  f[u] = v;
  for (int x : g[u])
    if (x != v)
      dfs(x, u);
  order.push_back(u);
}
int main() {
  while (cin >> n && n != -1) {
    if (n == 0)
      continue;
    order.clear();
    for (int i = 1; i <= n; i++)
      g[i].clear();
    for (int i = 0; i < n - 1; i++) {
      int a1, a2;
      cin >> a1 >> a2;
      g[a1].push_back(a2);
      g[a2].push_back(a1);
    }
    dfs(1, 0);
    for (int x : order) {
      d[x][0] = 1;
      d[x][1] = 0;
      for (int c : g[x])
        if (c != f[x]) {
          d[x][0] += min(d[c][0], d[c][1]);
          d[x][1] += d[c][2];
          if (d[x][0] > INF)
            d[x][0] = INF;
          if (d[x][1] > INF)
            d[x][1] = INF;
        }
      d[x][2] = INF;
      for (int c : g[x]) {
        d[x][2] = min(d[x][2], d[x][1] - d[c][2] + d[c][0]);
      }
    }
    cout << min(d[1][0], d[1][2]) << "\n";
  }
  return 0;
}