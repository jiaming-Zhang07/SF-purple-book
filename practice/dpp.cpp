#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
vector<int> G[maxn];
int n, d1[maxn], d2[maxn], son[maxn], up[maxn];
void dfs(int u, int v) {
  d1[u] = d2[u] = 0;
  for (int x : G[u])
    if (x != v) {
      dfs(x, u);
      if (d1[x] + 1 > d1[u]) {
        d2[u] = d1[u];
        d1[u] = d1[x] + 1;
        son[u] = x;
      } else if (d1[x] + 1 > d2[u])
        d2[u] = d1[x] + 1;
    }
}
void dfs2(int v, int p) {
  for (int u : G[v])
    if (u != p) {
      if (son[v] == u)
        up[u] = max(d2[v], up[v]) + 1;
      else
        up[u] = max(d1[v], up[v]) + 1;
      dfs2(u, v);
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
  dfs2(1, 0);
  for (int i = 1; i <= n; i++)
    cout << max(d1[i], up[i]) << (i == n ? "\n" : " ");
  return 0;
}