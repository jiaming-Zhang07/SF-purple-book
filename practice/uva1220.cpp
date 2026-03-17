#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int id, d[maxn][2], f[maxn][2];
vector<int> worker[maxn];
map<string, int> s;
int ID(string name) {
  if (s.count(name))
    return s[name];
  return s[name] = id++;
}
void dfs(int u, int ok) {
  f[u][ok] = 1;
  d[u][ok] = ok;
  for (int x : worker[u]) {
    if (!ok) {
      dfs(x, 1);
      dfs(x, 0);
      if (d[x][0] == d[x][1]) {
        d[u][ok] += d[x][0];
        f[u][ok] = 0;
      } else if (d[x][0] > d[x][1]) {
        d[u][ok] += d[x][0];
        if (!f[x][0])
          f[u][ok] = 0;
      } else if (d[x][1] > d[x][0]) {
        d[u][ok] += d[x][1];
        if (!f[x][1])
          f[u][ok] = 0;
      }
    } else {
      dfs(x, 0);
      d[u][ok] += d[x][0];
      if (!f[x][0])
        f[u][ok] = 0;
    }
  }
}
int main() {
  int n;
  while (cin >> n && n) {
    s.clear();
    id = 1;
    for (int i = 1; i <= n; i++)
      worker[i].clear();
    string name, name2;
    cin >> name;
    int boss = ID(name);
    for (int i = 1; i < n; i++) {
      cin >> name >> name2;
      worker[ID(name2)].push_back(ID(name));
    }
    dfs(boss, 0);
    dfs(boss, 1);
    if (d[boss][0] > d[boss][1]) {
      cout << d[boss][0];
      if (f[boss][0])
        cout << " Yes\n";
      else
        cout << " No\n";
    } else if (d[boss][1] > d[boss][0]) {
      cout << d[boss][1];
      if (f[boss][1])
        cout << " Yes\n";
      else
        cout << " No\n";
    } else
      cout << d[boss][0] << " No\n";
  }
  return 0;
}