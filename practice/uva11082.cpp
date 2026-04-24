#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int r[25], c[25], h[50], tot, mf[50], pre[50];
int s, t;
struct edge {
  int v, c, ne;
} e[1000];
void add(int u, int v, int c) {
  e[++tot] = {v, c, h[u]};
  h[u] = tot;
}
bool bfs() {
  memset(mf, 0, sizeof(mf));
  mf[s] = 1e9;
  queue<int> q;
  q.push(s);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = h[u]; i; i = e[i].ne) {
      int v = e[i].v;
      if (mf[v] == 0 && e[i].c) {
        pre[v] = i;
        mf[v] = min(mf[u], e[i].c);
        q.push(v);
        if (v == t)
          return true;
      }
    }
  }
  return false;
}
void EK() {
  while (bfs()) {
    int tt = t;
    while (tt) {
      int i = pre[tt];
      e[i].c -= mf[t];
      e[i ^ 1].c += mf[t];
      tt = e[i ^ 1].v;
    }
  }
}
int main() {
  int T, kase = 0;
  cin >> T;
  while (T--) {
    tot = 1;
    memset(h, 0, sizeof(h));
    int n, m;
    cin >> n >> m;
    t = n + m + 1;
    for (int i = 1; i <= n; i++)
      cin >> r[i];
    for (int i = n; i > 0; i--)
      r[i] -= r[i - 1];
    for (int i = 1; i <= m; i++)
      cin >> c[i];
    for (int i = m; i > 0; i--)
      c[i] -= c[i - 1];
    for (int i = 1; i <= n; i++) {
      add(0, i, r[i] - m);
      add(i, 0, 0);
    }
    for (int i = 1; i <= m; i++) {
      add(i + n, t, c[i] - n);
      add(t, i + n, 0);
    }
    for (int i = 1; i <= n; i++)
      for (int j = m; j >= 1; j--) {
        add(i, j + n, 19);
        add(j + n, i, 0);
      }
    EK();
    printf("Matrix %d\n", ++kase);
    for (int i = 1; i <= n; i++)
      for (int j = h[i]; j; j = e[j].ne)
        if (e[j].v)
          cout << 20 - e[j].c << (e[e[j].ne].v == 0 ? "\n" : " ");
    if (T)
      cout << "\n";
  }
  return 0;
}