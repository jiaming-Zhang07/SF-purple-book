#include <bits/stdc++.h>
using namespace std;
const int maxn = 105, maxs = 8, INF = 1e8;
int d[maxn][1 << maxs][1 << maxs];
int c[maxn], sub[maxn];
int s, m, n;
int dp(int i, int s0, int s1, int s2) {
  if (s2 == (1 << s) - 1)
    return 0;
  if (i == n)
    return INF;
  int &ans = d[i][s1][s2];
  if (ans != -1)
    return ans;
  ans = dp(i + 1, s0, s1, s2);
  int val = sub[i] & s0, val2 = sub[i] & s1;
  s0 ^= val;
  s1 |= val;
  s1 ^= val2;
  s2 |= val2;
  ans = min(ans, c[i] + dp(i + 1, s0, s1, s2));
  return ans;
}
int main() {
  while (cin >> s >> m >> n >> ws && s) {
    memset(d, -1, sizeof(d));
    memset(sub, 0, sizeof(sub));
    string str;
    int cc;
    int sumc = 0, s0 = (1 << s) - 1, s1 = 0, s2 = 0;
    for (int i = 0; i < m; i++) {
      getline(cin, str);
      stringstream ss(str);
      ss >> cc;
      sumc += cc;
      int t;
      while (ss >> t) {
        t--;
        if (s0 & 1 << t) {
          s0 ^= (1 << t);
          s1 |= 1 << t;
        } else if (s1 & 1 << t) {
          s1 ^= (1 << t);
          s2 |= 1 << t;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      getline(cin, str);
      stringstream ss(str);
      ss >> c[i];
      int t;
      while (ss >> t) {
        t--;
        sub[i] |= 1 << t;
      }
    }
    cout << sumc + dp(0, s0, s1, s2) << "\n";
  }
  return 0;
}