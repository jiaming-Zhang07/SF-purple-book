#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1 << 30;
int dist[1005][1005], pre[1005];
int main() {
  int n, m;
  cin >> n >> m;
  fill(&dist[0][0], &dist[0][0] + 1005 * 1005, INF);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    dist[u][v] = min(dist[u][v], w);
  }
  vector<int> d(n, INF);
  vector<bool> vis(n);
  d[0] = 0;
  for (int i = 0; i < n; i++) {
    int x, m = 1 << 30;
    for (int j = 0; j < n; j++)
      if (!vis[j] && d[j] < m)
        m = d[x = j];
    if (m == INF)
      break;
    vis[x] = true;
    for (int j = 0; j < n; j++)
      if (d[j] > d[x] + dist[x][j]) {
        pre[j] = x;
        d[j] = d[x] + dist[x][j];
      }
  }
  pre[0] = -1;
  for (int i = 1; i < n; i++) {
    if (d[i] == INF) {
      cout << "INF\n";
      continue;
    }
    int j = i;
    vector<int> route;
    route.push_back(i);
    while (pre[j] != -1) {
      route.push_back(pre[j]);
      j = pre[j];
    }
    for (int k = (int)route.size() - 1; k >= 0; k--)
      cout << route[k] << (k == 0 ? "\n" : " ");
  }
  return 0;
}