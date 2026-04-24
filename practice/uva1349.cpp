#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
struct edge {
  int v, c, w, ne;
} e[25000];
int h[210], s, t, tot = 1, d[210], vis[210], pre[210], mf[210];
void add(int u, int v, int c, int w) {
  e[++tot] = {v, c, w, h[u]};
  h[u] = tot;
}
bool spfa() {
  memset(d, 0x3f, sizeof(d));
  memset(vis, 0, sizeof(vis));
  memset(mf, 0, sizeof(mf));
  vis[s] = 1;
  queue<int> q;
  q.push(s);
  mf[s] = 1e9;
  d[s] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = h[u]; i; i = e[i].ne) {
      int v = e[i].v;
      if (e[i].c && d[v] > d[u] + e[i].w) {
        d[v] = d[u] + e[i].w;
        mf[v] = min(mf[u], e[i].c);
        pre[v] = i;
        if (!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
  }
  return mf[t];
}
int mwmc() {
  int flow = 0, ans = 0;
  while (spfa()) {
    flow += mf[t];
    ans += d[t];
    int tt = t;
    while (tt) {
      int i = pre[tt];
      e[i].c -= mf[t];
      e[i ^ 1].c += mf[t];
      tt = e[i ^ 1].v;
    }
  }
  if (flow < n)
    return -1;
  else
    return ans;
}
void read(int i) {
  while (1) {
    int m, w;
    cin >> m;
    if (m == 0)
      return;
    cin >> w;
    add(i + n, m, 1, w);
    add(m, i + n, 0, -w);
  }
}
int main() {
  while (cin >> n && n) {
    t = 2 * n + 1;
    tot = 1;
    memset(h, 0, sizeof(h));
    for (int i = 1; i <= n; i++) {
      read(i);
    }
    for (int i = 1; i <= n; i++) {
      add(0, i + n, 1, 0);
      add(i + n, 0, 0, 0);
      add(i, 2 * n + 1, 1, 0);
      add(2 * n + 1, i, 0, 0);
    }
    int ans = mwmc();
    if (ans < 0) {
      cout << "N\n";
      continue;
    } else
      cout << ans << "\n";
  }
  return 0;
}