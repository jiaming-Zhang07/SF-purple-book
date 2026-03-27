#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
struct str {
  string s, rev;
  bool operator<(const str &other) const {
    return s.size() < other.s.size();
  }
} s[20];
int n;
string ss[20][2];
int calc(int a, int x, int b, int y) {
  string s1 = ss[a][x], s2 = ss[b][y];
  for (int i = 1; i < s1.size(); i++)
    if (i + s2.size() > s1.size()) {
      bool inter = true;
      rep(j, s1.size() - i) if (s1[i + j] != s2[j]) {
        inter = false;
        break;
      }
      if (inter)
        return s1.size() - i;
    }
  return 0;
}
int interval[20][2][20][2];
void init() {
  sort(s, s + n);
  int n2 = 0;
  rep(i, n) {
    bool need = true;
    for (int j = i + 1; j < n; j++) {
      if (s[j].s.find(s[i].s) != string::npos || s[j].rev.find(s[i].s) != string::npos) {
        need = false;
        break;
      }
    }
    if (need) {
      ss[n2][0] = s[i].s;
      ss[n2][1] = s[i].rev;
      n2++;
    }
  }
  n = n2;
  rep(i, n) rep(x, 2) rep(j, n) rep(y, 2) {
    interval[i][x][j][y] = calc(i, x, j, y);
  }
}
int dp[1 << 16][20][2];
void solve() {
  dp[1][0][0] = ss[0][0].size();
  for (int a = 1; a < (1 << n) - 1; a++)
    rep(i, n) rep(x, 2) if (dp[a][i][x] > 0) {
      rep(j, n) if (!(a & 1 << j)) rep(y, 2) {
        dp[a | 1 << j][j][y] = dp[a | 1 << j][j][y] ? min(dp[a | 1 << j][j][y], dp[a][i][x] + (int)ss[j][y].size() - interval[i][x][j][y]) : dp[a][i][x] + (int)ss[j][y].size() - interval[i][x][j][y];
      }
    }
  int ans = 1 << 30;
  for (int i = 0; i < n; i++) {
    rep(x, 2) if (dp[(1 << n) - 1][i][x]) ans = min(ans, dp[(1 << n) - 1][i][x] - interval[i][x][0][0]);
  }
  if (ans <= 1)
    ans = 2;
  cout << ans << "\n";
}
int main() {
  while (cin >> n && n) {
    memset(dp, 0, sizeof(dp));
    rep(i, n) {
      cin >> s[i].s;
      s[i].rev = s[i].s;
      reverse(s[i].rev.begin(), s[i].rev.end());
    }
    init();
    solve();
  }
  return 0;
}