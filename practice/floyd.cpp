#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int d[105][105];
int main() {
  int n, m;
  cin >> n >> m;
  memset(d, 0x3f, sizeof(d));
  for (int i = 1; i <= n; i++)
    d[i][i] = 0;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    d[u][v] = d[v][u] = min(d[u][v], w);
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cout << d[i][j] << (j == n ? "\n" : " ");
  return 0;
}