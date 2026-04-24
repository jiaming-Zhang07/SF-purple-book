#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
  int v, c, w, ne;
} e[25000];
int h[1005 * 2], pre[2010], s = 1, t, tot = 1, v, ecnt, d[2010], mf[2010], vis[2010];
void add(int u, int v, int c, int w) {
  e[++tot] = {v, c, w, h[u]};
  h[u] = tot;
}
void spfa() {
  memset(d, 0x3f, sizeof(d));
  memset(mf, 0, sizeof(mf));
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  mf[s] = 1e9;
  d[s] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = h[u]; i; i = e[i].ne) {
      int v = e[i].v, c = e[i].c, w = e[i].w;
      if (c && d[u] + w < d[v]) {
        pre[v] = i;
        d[v] = d[u] + w;
        mf[v] = min(mf[u], c);
        if (!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
  }
}
int mwmc() {
  int ans = 0;
  for (int i = 0; i < 2; i++) {
    spfa();
    int tt = t;
    while (tt != s) {
      int i = pre[tt];
      e[i].c -= mf[t];
      e[i ^ 1].c += mf[t];
      tt = e[i ^ 1].v;
    }
    ans += d[t];
  }
  return ans;
}
int main() {
  while (cin >> v >> ecnt) {
    tot = 1;
    t = 2 * v;
    memset(h, 0, sizeof(h));
    for (int i = 2; i < v; i++) {
      add(2 * i - 1, 2 * i, 1, 0);
      add(2 * i, 2 * i - 1, 0, 0);
    }
    add(1, 2, 2, 0);
    add(2, 1, 0, 0);
    add(2 * v - 1, 2 * v, 2, 0);
    add(2 * v, 2 * v - 1, 0, 0);
    for (int i = 0; i < ecnt; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      add(2 * a, 2 * b - 1, 1, w);
      add(2 * b - 1, 2 * a, 0, -w);
    }
    cout << mwmc() << "\n";
  }
  return 0;
}