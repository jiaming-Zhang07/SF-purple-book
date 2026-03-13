#include <bits/stdc++.h>
using namespace std;
char s[1005];
int d[1005], vis[1005][1005];
bool p[1005][1005];
int kase;
bool ispalin(int i, int j) {
  if (i >= j)
    return true;
  if (s[i] != s[j])
    return false;
  if (vis[i][j] == kase)
    return p[i][j];
  vis[i][j] = kase;
  p[i][j] = ispalin(i + 1, j - 1);
  return p[i][j];
}
int main() {
  int T;
  cin >> T;
  for (kase = 1; kase <= T; kase++) {
    scanf("%s", s);
    int n = strlen(s);
    d[0] = 1;
    for (int i = 1; i < n; i++) {
      int ans = d[i - 1] + 1;
      for (int j = 0; j < i; j++)
        if (ispalin(j, i)) {
          if (j == 0)
            ans = 1;
          else
            ans = min(d[j - 1] + 1, ans);
        }
      d[i] = ans;
    }
    cout << d[n - 1] << "\n";
  }
  return 0;
}