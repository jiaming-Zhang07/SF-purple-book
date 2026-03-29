#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s1, s2;
int d[35][35];
ll way[35][35];
int main() {
  int T, kase = 0;
  cin >> T >> ws;
  while (T--) {
    getline(cin, s1);
    getline(cin, s2);
    int n1 = s1.size(), n2 = s2.size();
    s1 = " " + s1;
    s2 = " " + s2;
    for (int i = 1; i <= n1; i++) {
      d[i][0] = i;
      way[i][0] = 1;
    }
    for (int i = 1; i <= n2; i++) {
      d[0][i] = i;
      way[0][i] = 1;
    }
    way[0][0] = 1;
    d[0][0] = 0;
    for (int i = 1; i <= n1; i++)
      for (int j = 1; j <= n2; j++) {
        if (s1[i] == s2[j]) {
          d[i][j] = d[i - 1][j - 1] + 1;
          way[i][j] = way[i - 1][j - 1];
        } else if (d[i - 1][j] < d[i][j - 1]) {
          d[i][j] = d[i - 1][j] + 1;
          way[i][j] = way[i - 1][j];
        } else if (d[i - 1][j] > d[i][j - 1]) {
          d[i][j] = d[i][j - 1] + 1;
          way[i][j] = way[i][j - 1];
        } else {
          d[i][j] = d[i][j - 1] + 1;
          way[i][j] = way[i][j - 1] + way[i - 1][j];
        }
      }
    printf("Case #%d: %d %lld\n", ++kase, d[n1][n2], way[n1][n2]);
  }
  return 0;
}