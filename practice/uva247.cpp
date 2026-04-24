#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool d[30][30];
map<string, int> mp;
string name[30];
bool vis[30];
int tot;
int getid(string s) {
  if (mp.count(s))
    return mp[s];
  name[tot] = s;
  return mp[s] = tot++;
}
int n;
void print(int i) {
  vis[i] = true;
  for (int j = 0; j < n; j++)
    if (!vis[j] && d[i][j] && d[j][i]) {
      cout << ", " << name[j];
      print(j);
    }
}
int main() {
  int m, kase = 0;
  bool first = true;
  while (cin >> n >> m && n) {
    mp.clear();
    tot = 0;
    memset(d, 0, sizeof(d));
    for (int i = 0; i < m; i++) {
      string s1, s2;
      cin >> s1 >> s2;
      d[getid(s1)][getid(s2)] = true;
    }
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
          if (d[i][k] && d[k][j]) {
            d[i][j] = true;
          }
        }
    memset(vis, 0, sizeof(vis));
    if (!first)
      cout << "\n";
    else
      first = false;
    printf("Calling circles for data set %d:\n", ++kase);
    for (int i = 0; i < n; i++)
      if (!vis[i]) {
        cout << name[i];
        print(i);
        cout << "\n";
      }
  }
  return 0;
}