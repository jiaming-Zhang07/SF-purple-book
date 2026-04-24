#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
struct edge {
  int v, c, ne;
} e[25000];
int h[105 * 105], a[105][105], d[105 * 105], cur[105 * 105];
int s, t, tot = 1;
void add(int u, int v, int c, int bc) {
  e[++tot] = {v, c, h[u]};
  h[u] = tot;
  e[++tot] = {u, bc, h[v]};
  h[v] = tot;
}
bool bfs() {
  memset(d, 0, sizeof(d));
  queue<int> q;
  q.push(s);
  d[s] = 1;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = h[u]; i; i = e[i].ne) {
      int v = e[i].v;
      if (d[v] == 0 && e[i].c)
        d[v] = d[u] + 1;
      q.push(v);
      if (v == t)
        return true;
    }
  }
  return false;
}
int dfs(int u, int mf) {
  if (u == t)
    return mf;
  int sum = 0;
  for (int i = cur[u]; i; i = e[i].ne) {
    int v = e[i].c;
    if (d[v] == d[u] + 1) {
      int f = dfs(v, min(e[i].c, mf));
      mf -= f;
      sum += f;
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
int dinic() {
  int flow = 0;
  while (bfs()) {
    memcpy(cur, h, sizeof(h));
    flow += dfs(s, INF);
  }
  return flow;
}
int main() {
  int n, m;
  cin >> n >> m;
  s = n * m;
  t = s + 1;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1)
        add(s, i * m + j, INF, 0);
      else if (a[i][j])
        add(i * m + j, t, INF, 0);
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int cur = i * m + j;
      if (i + 1 < n)
        add(cur, cur + m, 1, 1);
      if (j + 1 < m)
        add(cur, cur + 1, 1, 1);
    }
  cout << dinic() << "\n";
  return 0;
}