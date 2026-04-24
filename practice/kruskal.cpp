#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5005;
int n, m, cnt;
struct edge {
  int u, v, w;
  bool operator<(const edge &b) const {
    return w < b.w;
  }
} e[200005];
int fa[maxn], ans;
int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool kruskal() {
  sort(e, e + m);
  for (int i = 0; i < n; i++)
    fa[i] = i;
  for (int i = 0; i < m; i++) {
    int x = find(e[i].u), y = find(e[i].v);
    if (x == y)
      continue;
    fa[x] = y;
    ans += e[i].w;
    cnt++;
  }
  return cnt == n - 1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> e[i].u >> e[i].v >> e[i].w;
  if (kruskal())
    cout << ans << "\n";
  else
    cout << "orz\n";
  return 0;
}