#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;
int head[2 * maxn], ne[2 * maxn], to[2 * maxn], tot;
int n;
ll dep[maxn], sum[maxn], sz[maxn];
void add(int u, int v) {
  tot++;
  to[tot] = v;
  ne[tot] = head[u];
  head[u] = tot;
}
void dfs(int u, int fa) {
  sz[u] = 1;
  dep[u] = dep[fa] + 1;
  sum[1] += dep[u];
  for (int i = head[u]; i; i = ne[i])
    if (to[i] != fa) {
      int v = to[i];
      dfs(v, u);
      sz[u] += sz[v];
    }
}
void dfs2(int u, int fa) {
  for (int i = head[u]; i; i = ne[i])
    if (to[i] != fa) {
      int v = to[i];
      sum[v] = sum[u] + n - sz[v] - sz[v];
      dfs2(v, u);
    }
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  dfs(1, 0);
  dfs2(1, 0);
  ll ans = sum[1], idx = 1;
  for (int i = 2; i <= n; i++)
    if (sum[i] > ans) {
      ans = sum[i];
      idx = i;
    }
  cout << idx << "\n";
  return 0;
}