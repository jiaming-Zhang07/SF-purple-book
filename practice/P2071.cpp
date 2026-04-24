#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2005;
struct edge {
  int v, ne;
} e[4 * maxn];
int h[2 * maxn], vis[2][maxn], match[2][maxn];
int tot = 1;
void add(int u, int v) {
  e[++tot] = {v, h[u]};
  h[u] = tot;
}
bool dfs(int u) {
  for (int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    for (int j = 0; j < 2; j++)
      if (!vis[j][v]) {
        vis[j][v] = 1;
        if (!match[j][v] || dfs(match[j][v])) {
          match[j][v] = u;
          return 1;
        }
      }
  }
  return 0;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    int a, b;
    cin >> a >> b;
    add(i, a);
    add(i, b);
  }
  int ans = 0;
  for (int i = 1; i <= 2 * n; i++) {
    memset(vis, 0, sizeof(vis));
    if (dfs(i))
      ans++;
  }
  cout << ans << "\n";
  return 0;
}