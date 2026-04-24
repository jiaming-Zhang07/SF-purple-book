#include <bits/stdc++.h>
using namespace std;
using ll = long long;
double p[25], sum[25], buy[25];
int n, r;
void dfs(int d, int c, double prob) {
  if (d - c > n - r || c > r)
    return;
  if (d == n) {
    sum[n] += prob;
    for (int i = 0; i < n; i++)
      if (buy[i])
        sum[i] += prob;
  }
  buy[d] = 0;
  dfs(d + 1, c, prob * (1 - p[d]));
  buy[d] = 1;
  dfs(d + 1, c + 1, prob * p[d]);
}
int main() {
  int kase = 0;
  while (cin >> n >> r && n) {
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i++)
      cin >> p[i];
    dfs(0, 0, 1);
    printf("Case %d:\n", ++kase);
    for (int i = 0; i < n; i++)
      printf("%.6f\n", sum[i] / sum[n]);
  }
  return 0;
}