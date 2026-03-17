#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
vector<int> G[maxn];
const int INF = 1 << 30;
int n;
int p[maxn], min_maxpart = INF, d[maxn], ans;
void dfs(int u, int v) {
  p[u] = v;
  d[u] = 1;
  int max_part = 0;
  for (int i = 0; i < G[u].size(); i++)
    if (G[u][i] != v) {
      dfs(G[u][i], u);
      d[u] += d[G[u][i]];
      max_part = max(d[G[u][i]], max_part);
    }
  max_part = max(n - d[u], max_part);
  if (max_part < min_maxpart) {
    min_maxpart = max_part;
    ans = u;
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a1, a2;
    cin >> a1 >> a2;
    G[a1].push_back(a2);
    G[a2].push_back(a1);
  }
  dfs(1, 0);
  cout << ans << "\n";
  return 0;
}