#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5005, maxm = 50005;
struct edge {
  int v, w, c, ne;
} e[2 * maxm];
int tot = 1, h[maxn];
void add(int u, int v, int w, int c) {
  e[++tot] = {v, w, c, h[u]};
  h[u] = tot;
}
int n, m, s, t;
ll d[maxn], flow, sumc;
ll mf[maxn], pre[maxn];
bool bellman() {
  memset(d, 0x3f, sizeof(d));
  memset(mf, 0, sizeof(mf));
  vector<bool> vis(n + 1);
  queue<int> q;
  q.push(s);
  vis[s] = true;
  mf[s] = 1ll << 60;
  d[s] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = false;
    for (int i = h[u]; i; i = e[i].ne) {
      int v = e[i].v;
      if (e[i].w && d[u] + e[i].c < d[v]) {
        mf[v] = min(mf[u], (ll)e[i].w);
        d[v] = d[u] + e[i].c;
        pre[v] = i;
        if (!vis[v]) {
          q.push(v);
          vis[v] = true;
        }
      }
    }
  }
  if (mf[t]) {
    flow += mf[t];
    sumc += mf[t] * d[t];
    return true;
  }
  return false;
}
int main() {
  cin >> n >> m >> s >> t;
  for (int i = 0; i < m; i++) {
    int u, v, w, c;
    cin >> u >> v >> w >> c;
    add(u, v, w, c);
    add(v, u, 0, -c);
  }
  while (bellman()) {
    int v = t;
    while (v != s) {
      int i = pre[v];
      e[i].w -= mf[t];
      e[i ^ 1].w += mf[t];
      v = e[i ^ 1].v;
    }
  }
  cout << flow << " " << sumc << "\n";
  return 0;
}