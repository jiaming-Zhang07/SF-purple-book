#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 45;
const double pi = acos(-1.0);
double pos[maxn], s[maxn][maxn], d[maxn][maxn][maxn];
int main() {
  int n, m;
  while (cin >> n >> m && n) {
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++)
      cin >> pos[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (i != j) {
          s[i][j] = 1 / 2.0 * sin(abs(pos[i] - pos[j]) * 2 * pi);
        }
    for (int k = 3; k <= m; k++)
      for (int i = 0; i < n; i++)
        for (int j = i + k - 1; j < n; j++)
          for (int t = i + k - 2; t < j; t++)
            d[k][i][j] = max(d[k][i][j], d[k - 1][i][t] + s[t][j] + s[i][t] - s[i][j]);
    double ans = 0;
    for (int i = 0; i < n - m + 1; i++)
      for (int j = i + m - 1; j < n; j++)
        ans = max(ans, d[m][i][j]);
    printf("%.6f\n", ans);
  }
  return 0;
}