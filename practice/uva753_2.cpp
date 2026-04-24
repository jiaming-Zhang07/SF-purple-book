#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
int target[105], sour[105], h[405], mf[405], pre[405];
map<string, int> mp;
int cnt = 1, s, t;
struct edge {
  int v, c, ne;
} e[25000];
int tot = 1;
void add(int u, int v, int c) {
  e[++tot] = {v, c, h[u]};
  h[u] = tot;
  e[++tot] = {u, 0, h[v]};
  h[v] = tot;
}
int getid(string s) {
  if (mp.count(s))
    return mp[s];
  return mp[s] = cnt++;
}
bool bfs() {
  memset(mf, 0, sizeof(mf));
  queue<int> q;
  mf[s] = 1e9;
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
  return 0;
}
int ek() {
  int ans = 0;
  while (bfs()) {
    int tt = t;
    while (tt) {
      int i = pre[tt];
      e[i].c -= mf[t];
      e[i ^ 1].c += mf[t];
      tt = e[i ^ 1].v;
    }
    ans += mf[t];
  }
  return ans;
}
int main() {
  int kase;
  cin >> kase;
  while (kase--) {
    memset(h, 0, sizeof(h));
    cnt = tot = 1;
    mp.clear();
    int n, m, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      target[i] = getid(s);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
      string s, s2;
      cin >> s >> s2;
      sour[i] = getid(s2);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
      string s, s2;
      cin >> s >> s2;
      add(getid(s), getid(s2), INF);
    }
    t = cnt;
    s = 0;
    for (int i = 0; i < m; i++)
      add(0, sour[i], 1);
    for (int i = 0; i < n; i++)
      add(target[i], t, 1);
    cout << m - ek() << "\n";
    if (kase)
      cout << "\n";
  }
  return 0;
}