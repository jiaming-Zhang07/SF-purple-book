#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2005, INF = 0x3f3f3f3f;
struct edge {
  int v, w;
};
vector<edge> e[maxn];
int d[maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      e[i].clear();
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      if (w >= 0) {
        e[u].push_back({v, w});
        e[v].push_back({u, w});
      } else
        e[u].push_back({v, w});
    }
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    bool flag;
    for (int i = 0; i < n; i++) {
      flag = false;
      for (int u = 1; u <= n; u++) {
        if (d[u] == INF)
          continue;
        for (auto x : e[u])
          if (d[x.v] > d[u] + x.w) {
            d[x.v] = d[u] + x.w;
            flag = true;
          }
      }
      if (!flag)
        break;
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}