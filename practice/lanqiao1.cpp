#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 1e5 + 5;
ll a[maxn], sum[maxn];
int main() {
  int n;
  cin >> n;
  vector<ll> dp(maxn), dp1(maxn), dp2(maxn), nexdp(maxn);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    dp[i] = abs(sum[i]);
  }
  for (int t = 0; t < 3; t++) {
    dp2[t] = dp1[t] = -1e15;
    for (int i = 1 + t; i <= n; i++) {
      dp1[i] = max(dp1[i - 1], dp[i] + sum[i]);
      dp2[i] = max(dp2[i - 1], dp[i] - sum[i]);
      nexdp[i + 1] = max(dp1[i] - sum[i + 1], dp2[i] + sum[i + 1]);
    }
    dp = nexdp;
  }
  cout << dp[n] << "\n";
  return 0;
}