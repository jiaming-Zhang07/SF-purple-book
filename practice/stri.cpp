#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int d[100][100];
int main() {
  string a, b;
  cin >> a >> b;
  int n1 = a.size(), n2 = b.size();
  for (int i = 1; i <= n2; i++)
    d[0][i] = i;
  for (int i = 1; i <= n1; i++)
    d[i][0] = i;
  d[0][0] = 0;
  for (int i = 1; i <= n1; i++)
    for (int j = 1; j <= n2; j++) {
      if (a[i - 1] == b[j - 1])
        d[i][j] = d[i - 1][j - 1];
      else
        d[i][j] = min({d[i - 1][j - 1] + 1, d[i][j - 1] + 1, d[i - 1][j] + 1});
    }
  cout << d[n1][n2] << "\n";
  return 0;
}