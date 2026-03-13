#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
int m, n;
int a[12][105], d[12][105], nex[12][105];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (cin >> m >> n) {
    int Ans = INF, first;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> a[i][j];
    for (int j = n - 1; j >= 0; j--)
      for (int i = 0; i < m; i++) {
        if (j == n - 1)
          d[i][j] = a[i][j];
        else {
          int r[3] = {i, i - 1, i + 1};
          if (i == 0)
            r[1] = m - 1;
          if (i == m - 1)
            r[2] = 0;
          sort(r, r + 3);
          int ans = INF;
          for (int k = 0; k < 3; k++)
            if (d[r[k]][j + 1] < ans) {
              ans = d[r[k]][j + 1];
              nex[i][j] = r[k];
            }
          d[i][j] = a[i][j] + ans;
        }
        if (j == 0 && d[i][j] < Ans) {
          Ans = d[i][j];
          first = i;
        }
      }
    for (int i = first, j = 0; j < n; i = nex[i][j], j++) {
      if (j)
        cout << " ";
      cout << i + 1;
    }
    cout << "\n" << Ans << "\n";
  }
  return 0;
}