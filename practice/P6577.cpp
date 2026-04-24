#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 505;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
ll w[maxn][maxn], la[maxn], lb[maxn], vis[maxn], slack[maxn], match[maxn], pre[maxn];
void bfs(int u) {
  memset(vis, 0, sizeof(vis));
  memset(slack, 0x3f, sizeof(slack));
  match[0] = u;
  int y = 0, yy;
  while (1) {
    ll delta = INF;
    int x = match[y];
    vis[y] = 1;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) {
        if (la[x] + lb[i] - w[x][i] < slack[i]) {
          slack[i] = la[x] + lb[i] - w[x][i];
          pre[i] = y;
        }
        if (slack[i] < delta) {
          delta = slack[i];
          yy = i;
        }
      }
    for (int i = 0; i <= n; i++)
      if (vis[i]) {
        lb[i] += delta;
        la[match[i]] -= delta;
      } else
        slack[i] -= delta;
    y = yy;
    if (!match[y])
      break;
  }
  while (y) {
    match[y] = match[pre[y]];
    y = pre[y];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  memset(w, 0xcf, sizeof(w));
  for (int i = 0; i < m; i++) {
    ll y, c, h;
    cin >> y >> c >> h;
    w[y][c] = max(w[y][c], h);
  }
  memset(la, 0xcf, sizeof(la));
  memset(lb, 0, sizeof(lb));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      la[i] = max(la[i], w[i][j]);
  for (int i = 1; i <= n; i++)
    bfs(i);
  ll ans = 0;
  for (int i = 1; i <= n; i++)
    ans += w[match[i]][i];
  cout << ans << "\n";
  for (int i = 1; i <= n; i++)
    cout << match[i] << (i == n ? "\n" : " ");
  return 0;
}