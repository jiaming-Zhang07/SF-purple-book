#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
int d[105][105];
int main() {
  int c, s, q, kase = 0;
  bool first = true;
  while (cin >> c >> s >> q && c) {
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= c; i++)
      d[i][i] = 0;
    for (int i = 0; i < s; i++) {
      int c1, c2, dd;
      cin >> c1 >> c2 >> dd;
      d[c1][c2] = d[c2][c1] = dd;
    }
    for (int k = 1; k <= c; k++)
      for (int i = 1; i <= c; i++)
        for (int j = 1; j <= c; j++)
          if (max(d[i][k], d[k][j]) < d[i][j]) {
            d[i][j] = max(d[i][k], d[k][j]);
          }
    if (!first)
      cout << "\n";
    else
      first = false;
    printf("Case #%d\n", ++kase);
    for (int i = 0; i < q; i++) {
      int a, b;
      cin >> a >> b;
      if (d[a][b] == INF)
        cout << "no path\n";
      else
        cout << d[a][b] << "\n";
    }
  }
  return 0;
}