#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 105;
int a[maxn][maxn], d[maxn][maxn];
int n, m;
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};
int dp(int i, int j) {
  int &ans = d[i][j];
  if (ans)
    return ans;
  ans = 1;
  int maxd = 0;
  for (int k = 0; k < 4; k++) {
    int nr = i + dr[k], nc = j + dc[k];
    if (nr < 0 || nc < 0 || nr >= n || nc >= m)
      continue;
    if (a[nr][nc] >= a[i][j])
      continue;
    maxd = max(maxd, dp(nr, nc));
  }
  ans += maxd;
  return ans;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(d, 0, sizeof(d));
    string name;
    cin >> name >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        ans = max(ans, dp(i, j));
      }
    cout << name << ": " << ans << "\n";
  }
  return 0;
}