#include <bits/stdc++.h>
using namespace std;
long long d[105][65];
int main() {
  int k;
  long long n;
  for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= 63; j++) {
      d[i][j] = d[i - 1][j - 1] + 1 + d[i][j - 1];
    }
  while (cin >> k >> n && k) {
    bool ok = false;
    for (int j = 1; j <= 63; j++)
      if (d[k][j] >= n) {
        ok = true;
        cout << j << "\n";
        break;
      }
    if (!ok)
      cout << "More than 63 trials needed.\n";
  }
  return 0;
}