#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}
int g[305][305];
int main() {
  int n, m;
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i <= 300; i++)
    for (int j = 1; j <= 300; j++)
      g[i][j] = gcd(i, j);
  while (cin >> n >> m && n) {
    int ans = 0;
    for (int a = 1; a < n; a++)
      for (int b = 1; b < m; b++)
        if (g[a][b] == 1)
          ans += (m - b) * (n - a) - max(0, n - 2 * a) * max(0, m - 2 * b);
    cout << 2 * ans << "\n";
  }
  return 0;
}