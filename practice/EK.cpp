#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
  int v, w, ne;
} e[10005];
int idx = 1, h[205];
void add(int u, int v, int c) {
  e[++idx] = {v, c, h[u]};
  h[u] = idx;
}
int pre[205], n, m, s, t;
int mf[205];
bool bfs() {
  memset(mf, 0, sizeof(mf));
  queue<int> q;
  q.push(s);
  mf[s] = 1e9;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = h[u]; i; i = e[i].ne)
      if (mf[e[i].v] == 0 && e[i].w) {
        pre[e[i].v] = i;
        mf[e[i].v] = min(mf[u], e[i].w);
        q.push(e[i].v);
        if (e[i].v == t)
          return true;
      }
  }
  return false;
}
int main() {
  cin >> n >> m >> s >> t;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    add(u, v, c);
    add(v, u, 0);
  }
  ll flow = 0;
  while (bfs()) {
    int v = t;
    while (v != s) {
      int i = pre[v];
      e[i].w -= mf[t];
      e[i ^ 1].w += mf[t];
      v = e[i ^ 1].v;
    }
    flow += mf[t];
  }
  cout << flow << "\n";
  return 0;
}