#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
struct edge {
  int v, c, ne;
} e[50000];
char g[55][55];
int s, t, h[3000], tot, d[3000], cur[3000];
void add(int u, int v, int c, int invc) {
  e[++tot] = {v, c, h[u]};
  h[u] = tot;
  e[++tot] = {u, invc, h[v]};
  h[v] = tot;
}
bool bfs() {
  memset(d, 0, sizeof(d));
  d[s] = 1;
  queue<int> q;
  q.push(s);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = h[u]; i; i = e[i].ne) {
      int v = e[i].v;
      if (d[v] == 0 && e[i].c) {
        d[v] = d[u] + 1;
        q.push(v);
        if (v == t)
          return true;
      }
    }
  }
  return false;
}
ll dfs(int u, ll mf) {
  if (u == t)
    return mf;
  ll sum = 0;
  for (int i = cur[u]; i; i = e[i].ne) {
    int v = e[i].v;
    cur[u] = i;
    if (d[v] == d[u] + 1 && e[i].c) {
      ll f = dfs(v, min(mf, (ll)e[i].c));
      sum += f;
      mf -= f;
      e[i].c -= f;
      e[i ^ 1].c += f;
      if (mf == 0)
        break;
    }
  }
  if (sum == 0)
    d[u] = 0;
  return sum;
}
void dinic(ll &ans) {
  while (bfs()) {
    memcpy(cur, h, sizeof(h));
    ans += dfs(s, 1e15);
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    tot = 1;
    memset(h, 0, sizeof(h));
    int w, h, d, f, b;
    cin >> w >> h >> d >> f >> b;
    s = h * w, t = h * w + 1;
    for (int i = 0; i < h; i++)
      cin >> g[i];
    ll ans = 0;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        int u = i * w + j;
        if (!i || !j || i == h - 1 || j == w - 1)
          add(s, u, INF, 0);
        if (j + 1 < w)
          add(u, u + 1, b, b);
        if (i + 1 < h)
          add(u, u + w, b, b);
        if (g[i][j] == '.') {
          add(i * w + j, t, f, 0);
        } else {
          add(s, i * w + j, d, 0);
        }
      }
    dinic(ans);
    cout << ans << "\n";
  }
  return 0;
}