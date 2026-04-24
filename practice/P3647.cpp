#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll W[2 * maxn], head[2 * maxn], to[2 * maxn], ne[2 * maxn], tot, dp[maxn][2], maxd[maxn], maxd2[maxn], son[maxn];
void add(int u, int v, int w) {
  tot++;
  W[tot] = w;
  to[tot] = v;
  ne[tot] = head[u];
  head[u] = tot;
}
ll ans;
void dfs(int u, int fa) {
  dp[u][0] = 0;
  maxd[u] = maxd2[u] = -INF;
  for (int i = head[u]; i; i = ne[i])
    if (to[i] != fa) {
      int v = to[i], w = W[i];
      dfs(v, u);
      ll cost_v = max(dp[v][0], dp[v][1] + w);
      dp[u][0] += cost_v;
      ll delta = dp[v][0] + w - cost_v;
      if (delta > maxd[u]) {
        son[u] = v;
        maxd2[u] = maxd[u];
        maxd[u] = delta;
      } else if (delta > maxd2[u])
        maxd2[u] = delta;
    }
  dp[u][1] = dp[u][0] + maxd[u];
}
void dfs2(int u, int fa, ll up0, ll up1, ll up_w) {
  ll best = fa == 0 ? 0 : max(up0, up1 + up_w);
  ans = max(ans, dp[u][0] + best);
  for (int i = head[u]; i; i = ne[i])
    if (to[i] != fa) {
      int v = to[i], w = W[i];
      ll nup0 = dp[u][0] - max(dp[v][0], dp[v][1] + w) + best;
      ll nup1, delta = up0 + up_w - best;
      if (son[u] == v)
        nup1 = nup0 + max(maxd2[u], delta);
      else
        nup1 = nup0 + max(maxd[u], delta);
      dfs2(v, u, nup0, nup1, w);
    }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, w);
  }
  dfs(1, 0);
  dfs2(1, 0, -INF, -INF, 0);
  cout << ans << "\n";
  return 0;
}