#include <bits/stdc++.h>
using namespace std;
int x0[20];
int yl[20];
char seq[20][105];
int a[20][20], ll[20], len[20];
int ok[20];
void hp(int x, int y, char c) {
  if (c == 'A')
    y++;
  else if (c == 'D')
    y--;
  else if (c == 'W')
    x++;
  else
    x--;
  a[x][y]--;
}
void mov(int &x, int &y, char c) {
  if (c == 'A')
    y--;
  else if (c == 'D')
    y++;
  else if (c == 'W')
    x--;
  else
    x++;
}
bool okk(int m) {
  for (int i = 1; i <= m; i++)
    if (x0[i] >= 0 && ok[i] < 2)
      return false;
  return true;
}
int main() {
  int h, w, m, l, x, y, cnt = 0;
  cin >> h >> w >> m >> l >> x >> y;
  cin >> seq[0];
  for (int i = 1; i <= m; i++) {
    cin >> x0[i];
    cin >> yl[i];
    cin >> len[i];
    cin >> seq[i];
    a[x0[i]][yl[i]]++;
  }
  for (int i = 0; i < l; i++) {
    if (seq[0][i] == 'A')
      y--;
    else if (seq[0][i] == 'D')
      y++;
    else if (seq[0][i] == 'W')
      x--;
    else
      x++;
    bool no = false;
    if (a[x][y]) {
      a[x][y] = 0;
      no = true;
    }
    vector<int> v;
    for (int i = 1; i <= m; i++)
      if (a[x0[i]][yl[i]] && x0[i] != -1) {
        if (no)
          continue;
        mov(x0[i], yl[i], seq[i][ll[i]]);
        v.push_back(i);
        hp(x0[i], yl[i], seq[i][ll[i]]);
        if (seq[i][ll[i] + 1] == '\0')
          ll[i] = 0;
        else
          ll[i]++;
      } else
        x0[i] = -1;
    for (int i = 0; i < v.size(); i++) {
      a[x0[v[i]]][yl[v[i]]]++;
    }
    if (a[x][y]) {
      a[x][y] = 0;
    }
  }
  for (int i = 1; i <= m; i++)
    if (x0[i] < 0)
      cnt++;
  cout << cnt << "\n";
}
