#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
  int v, ne;
} e[50005];
int h[505], vis[505], match[505];
int tot = 1;
void add(int u, int v) {
  e[++tot] = {v, h[u]};
  h[u] = tot;
}
bool dfs(int u) {
  for (int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (vis[v])
      continue;
    vis[v] = 1;
    if (!match[v] || dfs(match[v])) {
      match[v] = u;
      return 1;
    }
  }
  return 0;
}
int main() {
  int n, m, e;
  cin >> n >> m >> e;
  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    memset(vis, 0, sizeof(vis));
    if (dfs(i))
      ans++;
  }
  cout << ans << "\n";
  return 0;
}