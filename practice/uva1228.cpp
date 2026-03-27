#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const int maxn = 70;
int o[maxn], z[maxn];
ll dp[maxn][maxn];
int main() {
  ll n, d, k, kase = 0;
  while (cin >> n && n) {
    memset(dp, 0, sizeof(dp));
    cin >> d >> k;
    int zero = 0, one = 0;
    for (int i = n - 1; i >= 0; i--)
      if (k & 1ull << i)
        o[++one] = n - i;
      else
        z[++zero] = n - i;
    int t = 1, tt = 1;
    ll ma = 0, mi = 0;
    while (tt <= one) {
      if (t > zero || z[t] + d >= o[tt]) {
        ma += 1ull << (n + 1 - (t + tt));
        tt++;
      } else {
        t++;
      }
    }
    t = 1;
    tt = 1;
    while (tt <= one) {
      if (t <= zero && o[tt] + d >= z[t])
        t++;
      else {
        mi += 1ull << (n + 1 - (t + tt));
        tt++;
      }
    }
    dp[0][0] = 1;
    for (int i = 0; i <= one; i++)
      for (int j = 0; j <= zero; j++)
        if (i != one || j != zero) {
          if (j < zero && (i == one || o[i + 1] + d >= z[j + 1]))
            dp[i][j + 1] += dp[i][j];
          if (i < one && (j == zero || z[j + 1] + d >= o[i + 1]))
            dp[i + 1][j] += dp[i][j];
        }
    printf("Case %llu: %llu %llu %llu\n", ++kase, dp[one][zero], mi, ma);
  }
  return 0;
}
