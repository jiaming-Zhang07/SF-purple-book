#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll c(int k) {
  return k == 0 ? 1 : 3 * c(k - 1);
}
ll f(int k, int i) {
  if (i == 0)
    return 0;
  if (k == 0)
    return 1;
  if (i >= 1 << (k - 1))
    return 2 * c(k - 1) + f(k - 1, i - (1 << (k - 1)));
  else
    return 2 * f(k - 1, i);
}
int main() {
  int T, kase = 0;
  scanf("%d", &T);
  while (T--) {
    int k, a, b;
    scanf("%d%d%d", &k, &a, &b);
    printf("Case %d: %lld\n", ++kase, f(k, b) - f(k, a - 1));
  }
  return 0;
}