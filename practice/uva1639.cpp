#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long double lnc[200005];
void init(int n) {
  lnc[0] = 0;
  for (int k = 1; k <= n; k++)
    lnc[k] = lnc[k - 1] + log(n + k) - log(k);
}
int main() {
  int n, kase = 0;
  long double p;
  while (cin >> n >> p) {
    if (p == 0 || p == 1.0) {
      printf("Case %d: %.6Lf\n", ++kase, (long double)n);
      continue;
    }
    init(n);
    long double ans = 0;
    for (int k = 0; k <= n; k++) {
      ans += (n - k) * (exp(lnc[k] + (n + 1) * log(p) + k * log(1 - p)) + exp(lnc[k] + (n + 1) * log(1 - p) + k * log(p)));
    }
    printf("Case %d: %.6Lf\n", ++kase, ans);
  }
  return 0;
}