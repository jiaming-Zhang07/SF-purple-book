#include <bits/stdc++.h>
using namespace std;
const int maxn = 70 + 5;
const int lef = 1, righ = 2;
char seq[maxn];
int d[maxn][4][4][3], action[maxn][4][4][3];
int pos[100];
void update(int i, int a, int b, int s, int f, int t) {
  if (a == righ && b == lef)
    return;
  if (f == 1 && t == b)
    return;
  if (f == 2 && t == a)
    return;
  if (a == righ && f == 2 && t != b)
    return;
  else if (b == lef && f == 1 && t != a)
    return;
  int e = 0;
  if (f == 0)
    e = 0;
  else if (s != f)
    e = 1;
  else {
    if ((f == 1 && t == a) || (f == 2 && t == b))
      e = 3;
    else if ((f == 1 && t + a == 3) || (f == 2 && t + b == 3))
      e = 7;
    else
      e = 5;
  }
  int ta = a, tb = b;
  if (f == 1)
    ta = t;
  else if (f == 2)
    tb = t;
  if (e + d[i + 1][ta][tb][f] < d[i][a][b][s]) {
    d[i][a][b][s] = e + d[i + 1][ta][tb][f];
    action[i][a][b][s] = f * 4 + t;
  }
}
int main() {
  pos['L'] = 1;
  pos['R'] = 2;
  pos['D'] = 0;
  pos['U'] = 3;
  while (scanf("%s", seq) == 1 && seq[0] != '#') {
    memset(d, 0, sizeof(d));
    int n = strlen(seq);
    for (int i = n - 1; i >= 0; i--)
      for (int a = 0; a < 4; a++)
        for (int b = 0; b < 4; b++)
          if (a != b)
            for (int s = 0; s < 3; s++) {
              d[i][a][b][s] = 10 * n;
              if (seq[i] == '.') {
                update(i, a, b, s, 0, 0);
                for (int f = 1; f <= 2; f++)
                  for (int t = 0; t < 4; t++)
                    update(i, a, b, s, f, t);
              } else {
                update(i, a, b, s, 1, pos[seq[i]]);
                update(i, a, b, s, 2, pos[seq[i]]);
              }
            }
    int a = 1, b = 2, s = 0, f, t;
    for (int i = 0; i < n; i++) {
      f = action[i][a][b][s] / 4, t = action[i][a][b][s] % 4;
      s = f;
      if (f == 1) {
        a = t;
        cout << "L";
      } else if (f == 2) {
        cout << "R";
        b = t;
      } else
        cout << ".";
    }
    cout << "\n";
  }
  return 0;
}