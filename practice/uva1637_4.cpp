#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e6;
double dp[maxn];
char st[9][5];
double DP(int *d, int rem) {
  if (rem == 0)
    return 1;
  int mask = 0;
  for (int i = 0; i < 9; i++)
    mask = mask * 5 + d[i];
  double &an = dp[mask];
  if (an <= 1)
    return an;
  an = 0;
  int cnt = 0;
  for (int i = 0; i < 9; i++)
    if (d[i]) {
      for (int j = i + 1; j < 9; j++)
        if (d[j] && st[i][d[i]] == st[j][d[j]]) {
          d[i]--;
          d[j]--;
          cnt++;
          an += DP(d, rem - 2);
          d[j]++;
          d[i]++;
        }
    }
  if (cnt == 0)
    return an = 0;
  else
    return an /= cnt;
}
bool read() {
  string s;
  for (int i = 0; i < 9; i++)
    for (int j = 1; j <= 4; j++) {
      if (!(cin >> s))
        return false;
      st[i][j] = s[0];
    }
  return true;
}
int main() {
  while (read()) {
    fill(dp, dp + maxn, 2);
    int d[9];
    fill(d, d + 9, 4);
    cout << fixed << setprecision(6) << DP(d, 36) << "\n";
  }
  return 0;
}