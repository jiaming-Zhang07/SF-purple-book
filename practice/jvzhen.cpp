#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int r[1005], c[1005], d[1005][1005];
int dp(int s, int n) {
  if (d[s][n] < INF)
    return d[s][n];
  if (s >= n)
    return 0;
  int &ans = d[s][n];
  for (int i = s; i < n; i++)
    ans = min(ans, dp(s, i) + r[s] * c[i] * c[n] + dp(i + 1, n));
  return ans;
}
int main() {
  int n;
  cin >> n;
  memset(d, 0x3f, sizeof(d));
  for (int i = 0; i < n; i++)
    cin >> r[i] >> c[i];
  cout << dp(0, n - 1) << "\n";
  return 0;
}