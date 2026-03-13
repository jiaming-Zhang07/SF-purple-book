#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
char s1[5005], s2[5005];
int p[5005], q[5005], c[2][maxn], d[2][maxn], sq[26], eq[26], sp[26], ep[26];
int main() {
  int T;
  cin >> T;
  while (T--) {
    scanf("%s%s", s1 + 1, s2 + 1);
    int n = strlen(s1 + 1), m = strlen(s2 + 1);
    for (int i = 0; i < 26; i++) {
      sq[i] = sp[i] = 1 << 30;
      eq[i] = ep[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      p[i] = s1[i] - 'A';
      sp[p[i]] = min(sp[p[i]], i);
      ep[p[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
      q[i] = s2[i] - 'A';
      sq[q[i]] = min(sq[q[i]], i);
      eq[q[i]] = i;
    }
    int t = 0;
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (!i && !j)
          continue;
        int v1 = 1 << 30, v2 = 1 << 30;
        if (i)
          v1 = d[t ^ 1][j] + c[t ^ 1][j];
        if (j)
          v2 = d[t][j - 1] + c[t][j - 1];
        d[t][j] = min(v1, v2);
        if (i) {
          c[t][j] = c[t ^ 1][j];
          if (i == sp[p[i]] && sq[p[i]] > j)
            c[t][j]++;
          if (i == ep[p[i]] && eq[p[i]] <= j)
            c[t][j]--;
        } else if (j) {
          c[t][j] = c[t][j - 1];
          if (j == sq[q[j]])
            c[t][j]++;
          if (j == eq[q[j]] && ep[q[j]] <= i)
            c[t][j]--;
        }
      }
      t ^= 1;
    }
    cout << d[t ^ 1][m] << "\n";
  }
  return 0;
}