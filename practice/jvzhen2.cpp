#include <bits/stdc++.h>
using namespace std;
int a[50][50][50], b[50][50];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      for (int k = 0; k < m; k++)
        cin >> a[i][j][k];
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int r = 0; r < m; r++)
      for (int c = 0; c < m; c++) {
        int sum = 0;
        for (int k = 0; k < m; k++)
          sum += a[i][r][k] * a[i + 1][k][c];
        b[r][c] = sum & 1;
      }
    memcpy(a[i], b, sizeof(b));
  }
  for (int i = 0; i < m; i++) {
    cout << a[0][i][0];
    for (int j = 1; j < m; j++)
      cout << " " << a[0][i][j];
    cout << "\n";
  }
  return 0;
}