#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 10005, INF = 1 << 30;
int n, c1, c2;
vector<int> g[maxn];
int d[maxn][5];
void dfs(int u, int f) {
  d[u][0] = c1;
  d[u][1] = c2;
  d[u][2] = 0; // one son is ser
  d[u][3] = 0; // sons are all sol
  d[u][4] = 0; // sons arbitrary
  int need2 = INF;
  for (int v : g[u]) {
    if (v == f)
      continue;
    dfs(v, u);
    d[u][0] += min({d[v][0], d[v][1], d[v][2], d[v][3]});
    d[u][1] += min({d[v][0], d[v][1], d[v][2], d[v][3], d[v][4]});
    d[u][2] += min({d[v][0], d[v][1], d[v][2], d[v][3]});
    need2 = min(need2, d[v][1] - min({d[v][0], d[v][1], d[v][2], d[v][3]}));
    d[u][3] += min(d[v][0], d[v][2]);
    d[u][4] += min({d[v][0], d[v][1], d[v][2], d[v][3]});
  }
  d[u][2] += need2;
}
int main() {
  while (cin >> n >> c1 >> c2 && n) {
    for (int i = 1; i <= n; i++)
      g[i].clear();
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1, 0);
    cout << min({d[1][0], d[1][1], d[1][2], d[1][3]}) << "\n";
  }
  return 0;
}