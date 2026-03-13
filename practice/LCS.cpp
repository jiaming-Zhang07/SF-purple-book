#include <bits/stdc++.h>
using namespace std;
int a[1005], b[1005], d[1005][1005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= m; i++)
    cin >> b[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j])
        d[i][j] = d[i - 1][j - 1] + 1;
      else
        d[i][j] = max(d[i][j - 1], d[i - 1][j]);
    }
  return 0;
}