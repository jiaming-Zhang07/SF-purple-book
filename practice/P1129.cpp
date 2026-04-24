#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
  int v, ne;
} e[205 * 205];
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
  int T;
  cin >> T;
  while (T--) {
    memset(h, 0, sizeof(h));
    memset(match, 0, sizeof(match));
    tot = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        int t;
        cin >> t;
        if (t == 1)
          add(i, j);
      }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      memset(vis, 0, sizeof(vis));
      if (dfs(i))
        ans++;
    }
    cout << (ans == n ? "Yes\n" : "No\n");
  }
  return 0;
}