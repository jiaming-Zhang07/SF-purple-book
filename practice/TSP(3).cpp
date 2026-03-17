#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
int n;
double dist[maxn][maxn], d[1 << maxn][maxn];
int main() {
  cin >> n;
  for (int s = 0; s < 1 << n; s++)
    for (int i = 0; i < n; i++)
      d[s][n] = 1e15;
  d[1][0] = 0;
  for (int s = 1; s < 1 << n; s++)
    for (int i = 0; i < n; i++) {
      if (!(s & 1 << i))
        continue;
      if (d[s][i] >= 1e15)
        continue;
      for (int j = 0; j < n; j++)
        if (!(s & (1 << j)))
          d[s | (1 << j)][j] = min(d[s | (1 << j)][j], dist[i][j] + d[s][i]);
    }
  double ans = 1e15;
  for (int i = 0; i < n; i++)
    ans = min(ans, d[(1 << n) - 1][i]);
  printf("%.2f\n", ans);
  return 0;
}