#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2005;
struct edge {
  int v, w;
};
int n, m;
vector<edge> e[maxn];
int d[maxn];
bool SPFA(int s) {
  vector<int> cnt(n + 1);
  vector<bool> vis(n + 1);
  memset(d, 0x3f, sizeof(d));
  d[s] = 0;
  vis[s] = true;
  queue<int> q;
  q.push(s);
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = false;
    for (auto ed : e[u])
      if (d[ed.v] > d[u] + ed.w) {
        d[ed.v] = d[u] + ed.w;
        cnt[ed.v] = cnt[u] + 1;
        if (cnt[ed.v] >= n)
          return true;
        if (!vis[ed.v]) {
          q.push(ed.v);
          vis[ed.v] = true;
        }
      }
  }
  return false;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
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
    if (SPFA(1))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}