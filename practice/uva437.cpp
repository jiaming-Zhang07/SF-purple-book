#include <bits/stdc++.h>
using namespace std;
int n;
int s[35][3], dp[35][3];
void get_dim(int *v, int i, int j) {
  int cnt = 0;
  for (int k = 0; k < 3; k++)
    if (k != j) {
      v[cnt++] = s[i][k];
    }
}
int dpf(int i, int m) {
  if (dp[i][m] > 0)
    return dp[i][m];
  int v[2], v2[2];
  get_dim(v, i, m);
  for (int j = 0; j < n; j++)
    for (int k = 0; k < 3; k++) {
      get_dim(v2, j, k);
      if (v[0] > v2[0] && v[1] > v2[1])
        dp[i][m] = max(dp[i][m], dpf(j, k));
    }
  dp[i][m] += s[i][m];
  return dp[i][m];
}
int main() {
  int kase = 0;
  while (cin >> n && n) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++)
        cin >> s[i][j];
      sort(s[i], s[i] + 3);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int m = 0; m < 3; m++) {
        ans = max(ans, dpf(i, m));
      }
    printf("Case %d: maximum height = %d\n", ++kase, ans);
  }
  return 0;
}