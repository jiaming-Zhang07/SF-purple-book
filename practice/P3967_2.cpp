#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
int w[100][100], la[100], tla[100], lb[100], match[100], vis[100], slack[100], pre[100];
int n;
void bfs(int u) {
  memset(vis, 0, sizeof(vis));
  memset(slack, 0x3f, sizeof(slack));
  match[0] = u;
  int y = 0, yy = 0;
  while (1) {
    int delta = INF;
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
        la[match[i]] -= delta;
        lb[i] += delta;
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
int mc() {
  memset(match, 0, sizeof(match));
  for (int i = 1; i <= n; i++)
    bfs(i);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += w[match[i]][i];
  return ans;
}
int main() {
  cin >> n;
  fill(lb + 1, lb + n + 1, 0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> w[i][j];
      la[i] = max(w[i][j], la[i]);
    }
  memcpy(tla, la, sizeof(la));
  int ans = mc();
  cout << ans << "\n";
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++)
    v.push_back({match[i], i});
  sort(v.begin(), v.end());
  for (auto [a, b] : v) {
    int t = w[a][b];
    w[a][b] = -INF;
    memcpy(la, tla, sizeof(tla));
    memset(lb, 0, sizeof(lb));
    int res = mc();
    if (res < ans)
      cout << a << " " << b << "\n";
    w[a][b] = t;
  }
  return 0;
}