#include <bits/stdc++.h>
using namespace std;
int n, W;
int w[1005], v[1005], d[10005];
int dp(int i) {
  if (d[i] != -1)
    return d[i];
  d[i] = 0;
  for (int j = 0; j < n; j++)
    if (i >= w[j])
      d[i] = max(d[i], dp(i - w[j]) + v[j]);
  return d[i];
}
int main() {
  cin >> n >> W;
  for (int i = 0; i < n; i++)
    cin >> w[i] >> v[i];
  memset(d, -1, sizeof(d));
  cout << dp(W) << "\n";
  return 0;
}