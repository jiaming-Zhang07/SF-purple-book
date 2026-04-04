#include <bits/stdc++.h>
using namespace std;
string s, s2;
int n1, n2, d[55][5005];
using ll = long long;
bool check(int k) {
  memset(d, 0x3f, sizeof(d));
  for (int i = 0; i <= n1; i++)
    d[i][0] = i;
  for (int j = 1; j <= n2; j++) {
    d[0][j] = d[0][j - 1] + 1;
    for (int i = 1; i <= n1; i++) {
      if (s[i] == s2[j])
        d[i][j] = d[i - 1][j - 1];
      else {
        d[i][j] = min({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]}) + 1;
      }
    }
    if (d[n1][j] <= k) {
      if (j == n2)
        return true;
      for (int i = 0; i <= n1; i++)
        d[i][j] = min(d[i][j], i);
    }
  }
  return false;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> s >> s2;
    n1 = s.size();
    n2 = s2.size();
    s = " " + s;
    s2 = " " + s2;
    int L = 0, R = n1;
    while (L < R) {
      int mid = L + (R - L) / 2;
      if (check(mid))
        R = mid;
      else
        L = mid + 1;
    }
    cout << L << "\n";
  }
  return 0;
}