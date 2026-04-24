#include <bits/stdc++.h>
using namespace std;
using ll = long long;
double p[25], no[25];
int n;
double dfs(int s, int r, int o) {
  if (r == 0) {
    return no[n] / no[s];
  }
  double ans = 0;
  if (n - s < r)
    return 0;
  for (int i = s; i < n; i++)
    if (i != o) {
      ans += p[i] * (no[i] / no[s]) * dfs(i + 1, r - 1, o);
    }
  return ans;
}
int main() {
  int r, kase = 0;
  while (cin >> n >> r && n) {
    no[0] = 1;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      no[i + 1] = no[i] * (1 - p[i]);
    }
    double b = dfs(0, r, -1);
    printf("Case %d:\n", ++kase);
    for (int i = 0; i < n; i++)
      printf("%.6f\n", dfs(0, r - 1, i) / (no[i + 1] / no[i]) * p[i] / b);
  }
  return 0;
}