#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n1, n2;
string s, s2;
bool check(int k) {
  vector<int> dp(n1 + 1);
  vector<bool> valid(n2 + 1);
  for (int i = 0; i <= n1; i++)
    dp[i] = i;
  valid[0] = true;
  for (int j = 1; j <= n2; j++) {
    vector<int> ndp(n1 + 1);
    if (valid[j - 1])
      for (int i = 0; i <= n1; i++)
        dp[i] = min(dp[i], i);
    ndp[0] = dp[0] + 1;
    for (int i = 1; i <= n1; i++) {
      if (s2[j] == s[i])
        ndp[i] = dp[i - 1];
      else
        ndp[i] = min({dp[i], dp[i - 1], ndp[i - 1]}) + 1;
    }
    if (ndp[n1] <= k)
      valid[j] = true;
    dp = std::move(ndp);
  }
  return dp[n1] <= k;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> s >> s2;
    n1 = s.size();
    n2 = s2.size();
    s = " " + s;
    s2 = " " + s2;
    int L = 0, R = n1;
    while (L < R) {
      int mid = L + (R - L) / 2;
      if (check(mid))
        R = mid;
      else
        L = mid + 1;
    }
    cout << L << "\n";
  }
  return 0;
}