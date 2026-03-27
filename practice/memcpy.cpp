#include <bits/stdc++.h>
using namespace std;
string s[100005];
bool dp[100005][26][26];
int main() {
  int T, n, q;
  cin >> T;
  while (T--) {
    memset(dp, 0, sizeof(dp));
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      int a = s[i][0] - 'a', b = s[i].back() - 'a';
      memcpy(dp[i], dp[i - 1], sizeof(dp[i - 1]));
      dp[i][s[i][0] - 'a'][s[i].back() - 'a'] = true;
      for (int k = 0; k < 26; k++) {
        if (dp[i - 1][b][k])
          dp[i][a][k] = true;
        if (dp[i - 1][k][a])
          dp[i][k][b] = true;
      }
      for (int k = 0; k < 26; k++)
        for (int j = 0; j < 26; j++)
          if (dp[i - 1][k][a] && dp[i - 1][b][j])
            dp[i][k][j] = true;
    }
    for (int i = 0; i < q; i++) {
      char x, y;
      cin >> x >> y;
      int a = x - 'a', b = y - 'a';
      if (dp[n][a][b])
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
  return 0;
}