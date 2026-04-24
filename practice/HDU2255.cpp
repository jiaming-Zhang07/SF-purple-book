#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 305, INF = 0x3f3f3f3f;
int n, w[maxn][maxn], la[maxn], lb[maxn], va[maxn], vb[maxn], d[maxn], match[maxn];
bool dfs(int u) {
  va[u] = 1;
  for (int v = 1; v <= n; v++)
    if (!vb[v]) {
      if (la[u] + lb[v] == w[u][v]) {
        vb[v] = 1;
        if (!match[v] || dfs(match[v])) {
          match[v] = u;
          return 1;
        }
      } else
        d[v] = min(d[v], la[u] + lb[v] - w[u][v]);
    }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n) {
    memset(match, 0, sizeof(match));
    memset(w, 0xcf, sizeof(w));
    memset(la, 0xcf, sizeof(la));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        cin >> w[i][j];
        la[i] = max(la[i], w[i][j]);
      }
    for (int i = 1; i <= n; i++)
      lb[i] = 0;
    for (int i = 1; i <= n; i++)
      while (true) {
        fill(va + 1, va + n + 1, 0);
        fill(vb + 1, vb + n + 1, 0);
        fill(d + 1, d + n + 1, INF);
        if (dfs(i))
          break;
        int delta = INF;
        for (int i = 1; i <= n; i++)
          if (!vb[i])
            delta = min(delta, d[i]);
        for (int i = 1; i <= n; i++) {
          if (va[i])
            la[i] -= delta;
          if (vb[i])
            lb[i] += delta;
        }
      }
    int ans = 0;
    for (int i = 1; i <= n; i++)
      ans += w[match[i]][i];
    cout << ans << "\n";
  }
  return 0;
}