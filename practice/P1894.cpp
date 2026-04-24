#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
  int v, ne;
} e[40005];
int h[205], match[205], vis[205];
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
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
      int temp;
      cin >> temp;
      add(i, temp);
    }
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