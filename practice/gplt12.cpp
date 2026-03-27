#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Edge {
  int u, v;
  ll w;
};
struct edge {
  int to;
  ll w;
};
vector<ll> dij(int st, int n, const vector<vector<edge>> &e) {
  vector<ll> dist(n + 1, 1e18);
  dist[st] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push({0, st});
  while (!pq.empty()) {
    auto [d, id] = pq.top();
    pq.pop();
    if (d > dist[id])
      continue;
    for (auto [v, w] : e[id]) {
      if (dist[v] > dist[id] + w) {
        dist[v] = dist[id] + w;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<Edge> v(m);
  vector<vector<edge>> e(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> v[i].u >> v[i].v >> v[i].w;
    e[v[i].u].push_back({v[i].v, v[i].w});
    e[v[i].v].push_back({v[i].u, v[i].w});
  }
  vector<ll> d1 = dij(1, n, e);
  vector<ll> dn = dij(n, n, e);
  if (d1[n] == 1e18) {
    cout << -1 << "\n";
    return 0;
  }
  ll D = d1[n];
  vector<vector<edge>> newg(n + 1);
  for (auto [u, v, w] : v) {
    if (d1[u] + w + dn[v] > D + k)
      newg[u].push_back({v, w});
    if (d1[v] + w + dn[u] > D + k)
      newg[v].push_back({u, w});
  }
  vector<ll> ans = dij(1, n, newg);
  if (ans[n] == 1e18) {
    cout << -1 << "\n";
    return 0;
  }
  cout << ans[n] << "\n";
  return 0;
}