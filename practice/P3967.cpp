#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
  int v, c, w, ne;
} e[20000], ee[20000];
int tot = 1, h[200];
void add(int u, int v, int c, int w) {
  e[++tot] = {v, c, w, h[u]};
  h[u] = tot;
}
int vis[200], d[200], S, T, pre[200], mf[200], donot[20000], mark[20000];
bool bfs() {
  mf[S] = 1 << 30;
  mf[T] = 0;
  memset(d, 0xcf, sizeof(d));
  queue<int> q;
  d[S] = 0;
  q.push(S);
  vis[S] = 1;
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = h[u]; i; i = e[i].ne) {
      int v = e[i].v, w = e[i].w, c = e[i].c;
      if (c && !donot[i] && d[u] + w > d[v]) {
        d[v] = d[u] + w;
        pre[v] = i;
        mf[v] = min(mf[u], c);
        if (!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
  }
  return mf[T];
}
int mwmc() {
  int ans = 0;
  while (1) {
    int res = bfs();
    if (res == 0)
      break;
    int t = T;
    while (t) {
      int i = pre[t];
      e[i].c -= mf[T];
      e[i ^ 1].c += mf[T];
      t = e[i ^ 1].v;
    }
    ans += d[T] * res;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  S = 0, T = 2 * n + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int t;
      cin >> t;
      add(i, j + n, 1, t);
      add(j + n, i, 0, -t);
    }
  for (int i = 1; i <= n; i++) {
    add(0, i, 1, 0);
    add(i, 0, 0, 0);
    add(i + n, 2 * n + 1, 1, 0);
    add(2 * n + 1, i + n, 0, 0);
  }
  memcpy(ee, e, sizeof(e));
  int ans = mwmc();
  cout << ans << "\n";
  for (int i = 1; i <= n; i++)
    for (int j = h[i]; j; j = e[j].ne)
      if (!e[j].c)
        mark[j] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = h[i]; j; j = e[j].ne)
      if (mark[j]) {
        donot[j] = donot[j ^ 1] = 1;
        memcpy(e, ee, sizeof(ee));
        int temp = mwmc();
        if (temp < ans)
          cout << i << " " << e[j].v - n << "\n";
        donot[j] = donot[j ^ 1] = 0;
      }
  return 0;
}