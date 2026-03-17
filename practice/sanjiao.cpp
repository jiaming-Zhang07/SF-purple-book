#include <bits/stdc++.h>
using namespace std;
double x[105], y[105], dist[105][105], d[105][105];
double dp(int s, int e) {
  if (s == e - 1)
    return 0;
  double &ans = d[s][e];
  if (ans >= 0)
    return d[s][e];
  ans = 1e15;
  for (int i = s + 1; i < e; i++)
    ans = min(dist[s][e] + dist[s][i] + dist[i][e] + dp(i, e) + dp(s, i), ans);
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      d[i][j] = -1;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n; j++)
      dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
  cout << dp(0, n - 1);
  return 0;
}