#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
  int v, w, ne;
} e[100005 + 2 * 1005];
int h[6005], d[6005], cur[6005];
int tot = 1;
void add(int u, int v, int w) {
  e[++tot] = {v, w, h[u]};
  h[u] = tot;
}
int s = 0, t;
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
      if (d[v] == 0 && e[i].w) {
        d[v] = d[u] + 1;
        q.push(v);
        if (v == t)
          return true;
      }
    }
  }
  return false;
}
int dfs(int u, int mf) {
  int sum = 0;
  if (u == t)
    return mf;
  for (int i = cur[u]; i; i = e[i].ne) {
    cur[u] = i;
    int v = e[i].v;
    if (d[v] == d[u] + 1 && e[i].w) {
      int f = dfs(v, min(mf, e[i].w));
      mf -= f;
      sum += f;
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
int dinic() {
  int flow = 0;
  while (bfs()) {
    memcpy(cur, h, sizeof(h));
    flow += dfs(s, 1e9);
  }
  return flow;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    int a, b;
    cin >> a >> b;
    a = a + 2 * n;
    b = b + 2 * n;
    add(i, a, 1);
    add(a, i, 0);
    add(i, b, 1);
    add(b, i, 0);
  }
  t = 3 * n + 1;
  for (int i = 1; i <= 2 * n; i++) {
    add(0, i, 1);
    add(i, 0, 0);
  }
  for (int i = 1; i <= n; i++) {
    add(i + 2 * n, t, 2);
    add(t, i + 2 * n, 0);
  }
  cout << dinic() << "\n";
  return 0;
}