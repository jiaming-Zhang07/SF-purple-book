#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
vector<int> G[maxn];
const int INF = 1 << 30;
int n;
int min_maxpart = INF, d[maxn], ans;
void dfs(int u, int v) {
  d[u] = 0;
  for (int x : G[u])
    if (x != v) {
      dfs(x, u);
      ans = max(ans, d[x] + d[u] + 1);
      d[u] = max(d[x] + 1, d[u]);
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