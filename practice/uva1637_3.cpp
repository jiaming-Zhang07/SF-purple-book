#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<vector<int>, double> dp;
char st[9][5];
double DP(vector<int> &v, int c) {
  if (dp.count(v))
    return dp[v];
  if (c == 0)
    return dp[v] = 1;
  double an = 0;
  int cnt = 0;
  for (int i = 0; i < 9; i++)
    if (v[i]) {
      for (int j = i + 1; j < 9; j++)
        if (v[j] && st[i][v[i]] == st[j][v[j]]) {
          cnt++;
          v[i]--;
          v[j]--;
          an += DP(v, c - 2);
          v[j]++;
          v[i]++;
        }
    }
  if (cnt == 0)
    return dp[v] = 0;
  else
    return dp[v] = an / cnt;
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
    dp.clear();
    vector<int> v(9, 4);
    cout << fixed << setprecision(6) << DP(v, 36) << "\n";
  }
  return 0;
}