#include <bits/stdc++.h>
using namespace std;
using ll = long long;
double dp[5][5][5][5][5][5][5][5][5];
char st[9][5];
double DP(int *d) {
  double &an = dp[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]][d[6]][d[7]][d[8]];
  if (an <= 1)
    return an;
  bool win = true;
  for (int i = 0; i < 9; i++)
    if (d[i]) {
      win = false;
      break;
    }
  if (win)
    return an = 1;
  an = 0;
  int cnt = 0;
  for (int i = 0; i < 9; i++)
    if (d[i])
      for (int j = i + 1; j < 9; j++)
        if (d[j] && st[i][d[i]] == st[j][d[j]])
          cnt++;
  if (cnt == 0)
    return an;
  for (int i = 0; i < 9; i++)
    if (d[i]) {
      for (int j = i + 1; j < 9; j++)
        if (d[j] && st[i][d[i]] == st[j][d[j]]) {
          d[i]--;
          d[j]--;
          an += DP(d) / cnt;
          d[j]++;
          d[i]++;
        }
    }
  return an;
}
int main() {
  string s;
  while (cin >> s) {
    st[0][1] = s[0];
    fill((double *)dp, (double *)dp + (int)pow(5, 9), 2);
    for (int i = 0; i < 3; i++) {
      cin >> s;
      st[0][i + 2] = s[0];
    }
    for (int i = 1; i < 9; i++) {
      for (int j = 0; j < 4; j++) {
        cin >> s;
        st[i][j + 1] = s[0];
      }
    }
    int d[9];
    fill(d, d + 9, 4);
    cout << fixed << setprecision(6) << DP(d) << "\n";
  }
  return 0;
}