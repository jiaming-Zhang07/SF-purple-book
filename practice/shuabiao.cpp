#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> k(n), c(n);
  for (int i = 1; i <= n - 1; i++)
    cin >> k[i] >> c[i];
  vector<int> dp(n + 1, 1 << 30);
  dp[1] = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (dp[i] == 1 << 30)
      continue;
    int pos = i + k[i];
    if (pos > n)
      continue;
    dp[pos] = min(dp[i] + c[i], dp[pos]);
  }
  cout << dp[n];
  return 0;
}