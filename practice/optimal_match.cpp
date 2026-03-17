#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const double INF = 1e15;
double d[maxn], x[maxn], y[maxn], dist[maxn][maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
  for (int s = 1; s < 1 << n; s++) {
    int i;
    for (i = 0; i < n; i++)
      if (1 << i & s)
        break;
    d[s] = INF;
    for (int j = i + 1; j < n; j++)
      if (1 << j & s)
        d[s] = min(d[s], dist[i][j] + d[s ^ (1 << i) ^ (1 << j)]);
  }
  printf("%.2f\n", d[(1 << n) - 1]);
  return 0;
}