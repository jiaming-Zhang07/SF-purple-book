#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
  int v, w, ne;
} e[10005];
int tot = 1, h[205];
void add(int u, int v, int w) {
  e[++tot] = {v, w, h[u]};
  h[u] = tot;
}
int n, m, s, t;
int d[205], cur[205];
bool bfs() {
  memset(d, 0, sizeof(d));
  queue<int> q;
  q.push(s);
  d[s] = 1;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = h[u]; i; i = e[i].ne)
      if (d[e[i].v] == 0 && e[i].w) {
        d[e[i].v] = d[u] + 1;
        q.push(e[i].v);
        if (e[i].v == t)
          return true;
      }
  }
  return false;
}
ll dfs(int u, ll mf) {
  if (u == t)
    return mf;
  ll sum = 0;
  for (int i = cur[u]; i; i = e[i].ne) {
    cur[u] = i;
    int v = e[i].v;
    if (d[v] == d[u] + 1 && e[i].w) {
      ll f = dfs(v, min(mf, (ll)e[i].w));
      sum += f;
      mf -= f;
      e[i].w -= f;
      e[i ^ 1].w += f;
      if (mf == 0)
        break;
    }
  }
  if (sum == 0)
    d[u] = 0;
  return sum;
}
ll dinic() {
  ll flow = 0;
  while (bfs()) {
    memcpy(cur, h, sizeof h);
    flow += dfs(s, 1e16);
  }
  return flow;
}
int main() {
  cin >> n >> m;
  s = 1;
  t = n;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, 0);
  }
  cout << dinic() << " ";
  for (int i = 2; i <= m * 2 + 1; i += 2)
    if (e[i].w == 0) {
      e[i].w = 1;
      e[i ^ 1].w = 0;
    } else {
      e[i].w += e[i ^ 1].w;
      e[i ^ 1].w = 0;
    }
  cout << dinic();
  return 0;
}