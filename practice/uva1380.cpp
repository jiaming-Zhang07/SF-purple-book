#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 205, INF = 1 << 30;
struct edge {
  int v, t; // 1:down,2:up,0:equal
};
int n, maxlen, f[maxn], g[maxn];
vector<edge> e[maxn];
bool havefa[maxn];
bool getinput() {
  n = 0;
  for (int i = 0; i < maxn; i++)
    e[i].clear();
  memset(havefa, 0, sizeof(havefa));
  int a;
  bool havedata = false;
  while (cin >> a && a) {
    if (a > n)
      n = a;
    havedata = true;
    string s;
    while (cin >> s && s != "0") {
      char c = s[s.size() - 1];
      if (isalpha(c)) {
        int t = 2;
        if (c == 'd')
          t = 1;
        stringstream ss(s.substr(0, s.size() - 1));
        int b;
        ss >> b;
        havefa[b] = true;
        n = max(n, b);
        e[a].push_back({b, t});
        e[b].push_back({a, (1 ^ (t - 1)) + 1});
      } else {
        e[a].push_back({stoi(s), 0});
        n = max(n, stoi(s));
        havefa[stoi(s)] = true;
      }
    }
  }
  return havedata;
}
struct noedge {
  int w, f, g;
};
bool cmp_f(const noedge a1, const noedge a2) {
  return a1.f < a2.f;
}
bool cmp_g(const noedge a1, const noedge a2) {
  return a1.g < a2.g;
}
bool dp(int u, int fa) {
  int f0 = 0, g0 = 0;
  vector<noedge> son;
  for (int i = 0; i < e[u].size(); i++)
    if (e[u][i].v != fa) {
      int v = e[u][i].v;
      dp(e[u][i].v, u);
      if (e[u][i].t == 1)
        g0 = max(g0, g[v] + 1);
      else if (e[u][i].t == 2)
        f0 = max(f0, f[v] + 1);
      else {
        son.push_back({v, f[v], g[v]});
      }
    }
  if (son.empty()) {
    if (g0 + f0 <= maxlen) {
      f[u] = f0;
      g[u] = g0;
      return true;
    } else {
      f[u] = g[u] = INF;
      return false;
    }
  }
  f[u] = g[u] = INF;
  sort(son.begin(), son.end(), cmp_f);
  int maxg[maxn + 1];
  maxg[son.size()] = g0;
  for (int i = (int)son.size() - 1; i >= 0; i--)
    maxg[i] = max(maxg[i + 1], son[i].g + 1);
  for (int p = 0; p <= son.size(); p++) {
    int ff = f0, gg = maxg[p];
    if (p > 0)
      ff = max(ff, son[p - 1].f + 1);
    if (ff + gg <= maxlen)
      f[u] = min(ff, f[u]);
  }
  sort(son.begin(), son.end(), cmp_g);
  int maxf[maxn + 1];
  maxf[son.size()] = f0;
  for (int i = (int)son.size() - 1; i >= 0; i--)
    maxf[i] = max(maxf[i + 1], son[i].f + 1);
  for (int p = 0; p <= son.size(); p++) {
    int ff = maxf[p], gg = g0;
    if (p > 0)
      gg = max(gg, son[p - 1].g + 1);
    if (ff + gg <= maxlen)
      g[u] = min(gg, g[u]);
  }
  return f[u] != INF;
}
int dfs(int i) {
  int ans = 0;
  for (int j = 0; j < e[i].size(); j++)
    if (e[i][j].t == 1) {
      ans = max(ans, dfs(e[i][j].v) + 1);
    }
  return ans;
}
int main() {
  while (getinput()) {
    int root = 1;
    for (int i = 1; i <= n; i++)
      if (!havefa[i] && !e[i].empty()) {
        root = i;
        break;
      }
    maxlen = 0;
    for (int i = 1; i <= n; i++)
      maxlen = max(maxlen, dfs(i));
    if (dp(root, -1))
      cout << maxlen + 1 << "\n";
    else
      cout << maxlen + 2 << "\n";
  }
  return 0;
}