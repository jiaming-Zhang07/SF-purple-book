#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxm = 1e5 + 5, maxn = 5e3 + 5, INF = 0x3f3f3f3f;
struct edge {
  int v, w, c, ne;
} e[maxm];
int tot = 1, h[maxn], dp[maxn], cur[maxn];
bool vis[maxn];
int n, m, s, t;
void add(int u, int v, int w, int c) {
  e[++tot] = {v, w, c, h[u]};
  h[u] = tot;
}
ll cost = 0;
ll dfs(int u, ll mf) {
  if (u == t)
    return mf;
  vis[u] = true;
  ll sum = 0;
  for (int i = cur[u]; i; i = e[i].ne) {
    cur[u] = i;
    int v = e[i].v;
    if (!vis[v] && e[i].w && dp[v] == dp[u] + e[i].c) {
      ll k = dfs(v, min(mf, (ll)e[i].w));
      e[i].w -= k;
      e[i ^ 1].w += k;
      mf -= k;
      sum += k;
      if (mf == 0)
        break;
    }
  }
  vis[u] = false;
  if (sum == 0)
    dp[u] = INF;
  return sum;
}
bool spfa() {
  memset(vis, 0, sizeof(vis));
  memset(dp, 0x3f, sizeof(dp));
  dp[s] = 0;
  queue<int> q;
  q.push(s);
  vis[s] = true;
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = false;
    for (int i = h[u]; i; i = e[i].ne) {
      int v = e[i].v;
      if (e[i].w && dp[u] + e[i].c < dp[v]) {
        dp[v] = dp[u] + e[i].c;
        if (!vis[v]) {
          q.push(v);
          vis[v] = true;
        }
      }
    }
  }
  return dp[t] != INF;
}
int main() {
  cin >> n >> m >> s >> t;
  for (int i = 0; i < m; i++) {
    int u, v, w, c;
    cin >> u >> v >> w >> c;
    add(u, v, w, c);
    add(v, u, 0, -c);
  }
  ll flow = 0, cost = 0;
  while (spfa()) {
    memcpy(cur, h, sizeof(h));
    int temp = dfs(s, 1e16);
    flow += temp;
    cost += temp * dp[t];
  }
  cout << flow << " " << cost;
  return 0;
}