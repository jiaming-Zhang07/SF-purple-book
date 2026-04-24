#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> e[maxn];
int main() {
  int n, m, s;
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
  }
  vector<int> d(n + 1, INF);
  d[s] = 0;
  vector<bool> done(n + 1);
  priority_queue<pair<int, int>> pq;
  pq.push({-d[s], s});
  while (!pq.empty()) {
    auto t = pq.top();
    pq.pop();
    int u = t.second;
    if (done[u])
      continue;
    done[u] = true;
    for (int i = 0; i < e[u].size(); i++)
      if (e[u][i].second + d[u] < d[e[u][i].first]) {
        d[e[u][i].first] = e[u][i].second + d[u];
        pq.push({-d[e[u][i].first], e[u][i].first});
      }
  }
  for (int i = 1; i <= n; i++)
    cout << d[i] << (i == n ? "\n" : " ");
  return 0;
}