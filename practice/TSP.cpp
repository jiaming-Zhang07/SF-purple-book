#include <bits/stdc++.h>
using namespace std;
double dist[10][10], d[10][1 << 10];
int main() {
  int n;
  cin >> n;
  n--;
  for (int i = 0; i < n; i++)
    d[i][0] = dist[i + 1][0];
  for (int s = 1; s < (1 << n) - 1; s++) {
    for (int i = 0; i < n; i++)
      if ((s & (1 << i)) == 0) {
        d[i][s] = 1e15;
        for (int j = 0; j < n; j++)
          if (s & (1 << j))
            d[i][s] = min(d[i][s], dist[i + 1][j + 1] + d[j][s ^ (1 << j)]);
      }
  }
  double ans = 1e15;
  for (int i = 0; i < n; i++)
    ans = min(ans, dist[0][i + 1] + d[i][((1 << n) - 1) ^ (1 << i)]);
  printf("%.2f\n", ans);
  return 0;
}