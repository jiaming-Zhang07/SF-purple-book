#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 21;
ll d[maxn][maxn][maxn];
int main() {
  d[1][1][1] = 1;
  for (int i = 2; i <= maxn - 1; i++)
    for (int j = 1; j <= maxn - 1; j++)
      for (int k = 1; k <= maxn - 1; k++) {
        d[i][j][k] = (i - 2) * d[i - 1][j][k] + d[i - 1][j - 1][k] + d[i - 1][j][k - 1];
      }
  int T;
  cin >> T;
  while (T--) {
    int n, l, r;
    cin >> n >> l >> r;
    cout << d[n][l][r] << "\n";
  }
  return 0;
}