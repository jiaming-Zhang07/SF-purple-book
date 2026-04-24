#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<string, int> mp;
int cnt;
struct edge {
  int v, c, ne;
} e[25000];
int tot = 1, sour[105], target[105], h[205], ok[505][505], vis[205], pre[205];
int getid(string s) {
  if (mp.count(s))
    return mp[s];
  return mp[s] = cnt++;
}
void add(int u, int v) {
  e[++tot] = {v, 1, h[u]};
  h[u] = tot;
  e[++tot] = {u, 0, h[v]};
  h[v] = tot;
}
int S, T;
bool bfs() {
  memset(vis, 0, sizeof(vis));
  vis[S] = 1;
  queue<int> q;
  q.push(S);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = h[u]; i; i = e[i].ne)
      if (e[i].c && !vis[e[i].v]) {
        vis[e[i].v] = 1;
        q.push(e[i].v);
        pre[e[i].v] = i;
        if (e[i].v == T)
          return true;
      }
  }
  return false;
}
int mc() {
  int ans = 0;
  while (bfs()) {
    int t = T;
    ans++;
    while (t != S) {
      int i = pre[t];
      e[i].c -= 1;
      e[i ^ 1].c += 1;
      t = e[i ^ 1].v;
    }
  }
  return ans;
}
int main() {
  int TT;
  cin >> TT;
  while (TT--) {
    mp.clear();
    cnt = 0;
    tot = 1;
    memset(h, 0, sizeof(h));
    memset(ok, 0, sizeof(ok));
    int n, m, k;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
      cin >> s;
      target[i] = getid(s);
    }
    cin >> m;
    string s2;
    for (int i = 0; i < m; i++) {
      cin >> s >> s2;
      sour[i] = getid(s);
      ok[sour[i]][getid(s2)] = 1;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
      cin >> s >> s2;
      ok[getid(s)][getid(s2)] = 1;
    }
    for (int k = 0; k < cnt; k++)
      for (int i = 0; i < cnt; i++)
        for (int j = 0; j < cnt; j++)
          ok[i][j] = ok[i][j] | (ok[i][k] && ok[k][j]);
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        if (ok[sour[i - 1]][target[j - 1]])
          add(i, j + m);
    S = 0, T = n + m + 1;
    for (int i = 1; i <= m; i++)
      add(0, i);
    for (int j = 1; j <= n; j++)
      add(j + m, n + m + 1);
    cout << m - mc() << "\n";
    if (TT)
      cout << "\n";
  }
  return 0;
}