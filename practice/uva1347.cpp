#include <bits/stdc++.h>
using namespace std;
double x[55], y[55], dist[55][55], d[55][55];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; i++)
      cin >> x[i] >> y[i];
    for (int i = 1; i < n; i++)
      for (int j = i + 1; j <= n; j++)
        dist[i][j] = sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]));
    for (int i = n; i >= 2; i--)
      for (int j = 1; j < i; j++) {
        if (i == n)
          d[i][j] = dist[j][i];
        else
          d[i][j] = min(dist[i][i + 1] + d[i + 1][j], dist[j][i + 1] + d[i + 1][i]);
      }
    printf("%.2f\n", dist[1][2] + d[2][1]);
  }
  return 0;
}