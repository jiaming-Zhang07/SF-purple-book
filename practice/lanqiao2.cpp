#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3005;
ll p[4][maxn], tran[maxn][4];
int ne[maxn];
char s[maxn];
int id[256];
const int mod = 998244353;
int main() {
  int n, m;
  cin >> n >> m;
  scanf("%s", s + 1);
  id['A'] = 0;
  id['T'] = 1;
  id['G'] = 2;
  id['C'] = 3;
  for (int i = 0; i < n; i++) {
    cin >> p[0][i] >> p[1][i] >> p[2][i] >> p[3][i];
  }
  ne[1] = 0;
  for (int i = 2, j = 0; i <= m; i++) {
    while (j && s[j + 1] != s[i])
      j = ne[j];
    if (s[j + 1] == s[i])
      j++;
    ne[i] = j;
  }
  for (int j = 0; j < m; j++)
    for (int c = 0; c < 4; c++) {
      if (j == 0)
        tran[0][c] = (c == id[s[1]] ? 1 : 0);
      else {
        if (c == id[s[j + 1]])
          tran[j][c] = j + 1;
        else
          tran[j][c] = tran[ne[j]][c];
      }
    }
  vector<ll> dp(m, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    vector<ll> nexdp(m, 0);
    for (int j = 0; j < m; j++)
      if (dp[j]) {
        for (int c = 0; c < 4; c++)
          if (tran[j][c] < m)
            nexdp[tran[j][c]] = (nexdp[tran[j][c]] + dp[j] * p[c][i]) % mod;
      }
    dp = nexdp;
  }
  ll no = 0;
  for (int i = 0; i < m; i++)
    no = (dp[i] + no) % mod;
  cout << (1 - no + mod) % mod << "\n";
  return 0;
}