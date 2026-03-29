#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 10005;
ll p[maxn], ti[maxn], d[2][maxn][2];
const ll INF = 1e15;
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      cin >> p[i] >> ti[i];
    int t = 0;
    for (int i = 0; i < n; i++)
      d[0][i][0] = d[0][i][1] = 0;
    for (int len = 1; len < n; len++) {
      t ^= 1;
      for (int i = 0; i < n - len; i++)
        d[t][i][0] = d[t][i][1] = INF;
      for (int i = 0; i < n - len; i++) {
        if (d[t ^ 1][i + 1][1] + p[i + len] - p[i] < ti[i])
          d[t][i][0] = min(d[t][i][0], d[t ^ 1][i + 1][1] + p[i + len] - p[i]);
        if (d[t ^ 1][i + 1][0] + p[i + 1] - p[i] < ti[i])
          d[t][i][0] = min(d[t][i][0], d[t ^ 1][i + 1][0] + p[i + 1] - p[i]);
        if (d[t ^ 1][i][1] + p[i + len] - p[i + len - 1] < ti[i + len])
          d[t][i][1] = min(d[t][i][1], d[t ^ 1][i][1] + p[i + len] - p[i + len - 1]);
        if (d[t ^ 1][i][0] + p[i + len] - p[i] < ti[i + len])
          d[t][i][1] = min(d[t][i][1], d[t ^ 1][i][0] + p[i + len] - p[i]);
      }
    }
    ll ans1 = min(d[t][0][0], d[t][0][1]);
    if (ans1 < INF)
      cout << ans1 << "\n";
    else
      cout << "No solution\n";
  }
  return 0;
}