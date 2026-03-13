#include <bits/stdc++.h>
using namespace std;
int m, k;
bool g[305][305];
bool solve() {
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++) {
      bool shared = false, diff = false;
      for (int v = 0; v < m; v++) {
        if (g[i][v] && g[j][v])
          shared = true;
        if (g[i][v] != g[j][v])
          diff = true;
        if (shared && diff)
          return false;
      }
    }
  return true;
}
int main() {
  int T, kase = 0;
  cin >> T;
  while (T--) {
    memset(g, 0, sizeof(g));
    cout << "Case #" << ++kase << ": ";
    cin >> m >> k;
    for (int i = 0; i < k; i++) {
      int a1, a2;
      cin >> a1 >> a2;
      g[a1][a2] = true;
    }
    if (solve())
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}