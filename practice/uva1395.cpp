#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
  int u, v, w;
  bool operator<(const edge &b) const {
    return w < b.w;
  }
} e[10000];
int fa[105];
int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
};
int ans;
int main() {
  int n, m;
  while (cin >> n >> m && n) {
    ans = 1 << 30;
    for (int i = 0; i < m; i++)
      cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e, e + m);
    for (int l = 0; l < m; l++) {
      int cnt = 0;
      for (int i = 1; i <= n; i++)
        fa[i] = i;
      for (int j = l; j < m; j++) {
        int x = find(e[j].u), y = find(e[j].v);
        if (x == y)
          continue;
        fa[x] = y;
        cnt++;
        if (cnt == n - 1) {
          ans = min(ans, e[j].w - e[l].w);
          break;
        }
      }
    }
    cout << (ans == 1 << 30 ? -1 : ans) << "\n";
  }
  return 0;
}