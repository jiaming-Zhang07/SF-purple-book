#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int c[205], d[205][205][205];
int dp(int l, int r, int k) {
  if (l > r)
    return 0;
  int &ans = d[l][r][k];
  if (ans > 0)
    return ans;
  int p = r - 1;
  while (p >= l && c[p] == c[r])
    p--;
  p++;
  ans = dp(l, p - 1, 0) + (r - p + 1 + k) * (r - p + 1 + k);
  for (int i = l; i < r; i++)
    if (c[i] == c[r] && c[i + 1] != c[i])
      ans = max(ans, dp(l, i, r - p + 1 + k) + dp(i + 1, p - 1, 0));
  return ans;
}
int main() {
  int T;
  scanf("%d", &T);
  for (int kase = 1; kase <= T; kase++) {
    memset(d, 0, sizeof(d));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &c[i]);
    printf("Case %d: %d\n", kase, dp(0, n - 1, 0));
  }
  return 0;
}