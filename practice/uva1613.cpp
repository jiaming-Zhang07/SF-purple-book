#include <bits/stdc++.h>
using namespace std;
int used[10005], color[10005], visited[10005];
vector<int> g[10005];
int main() {
  int n, m, kase = 0;
  while (scanf("%d%d", &n, &m) == 2) {
    if (kase++)
      printf("\n");
    int d1, d2, maxd = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &d1, &d2);
      g[d1].push_back(d2);
      g[d2].push_back(d1);
      maxd = max({(int)g[d1].size(), (int)g[d2].size(), maxd});
    }
    if ((maxd & 1) == 0)
      maxd++;
    int k = maxd;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      int r = q.front();
      q.pop();
      for (int i = 0; i < (int)g[r].size(); i++) {
        if (color[g[r][i]]) {
          used[color[g[r][i]]] = r;
          continue;
        }
        if (!visited[g[r][i]]) {
          visited[g[r][i]] = 1;
          q.push(g[r][i]);
        }
      }
      for (int i = 1; i <= k; i++)
        if (used[i] != r) {
          color[r] = i;
          break;
        }
    }
    printf("%d\n", k);
    for (int i = 1; i <= n; i++)
      printf("%d\n", color[i]);
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      color[i] = 0;
      visited[i] = 0;
    }
    for (int i = 1; i <= k; i++)
      used[i] = 0;
  }
  return 0;
}