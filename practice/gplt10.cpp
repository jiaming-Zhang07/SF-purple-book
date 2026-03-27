#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, k, o, d;
};
char a[1005][1005];
int lk[1005][1005][2];
int main() {
  int n, m, k, x, y, ex, ey;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    char *p = strchr(a[i], 'S');
    if (p != NULL) {
      y = p - a[i];
      x = i;
    }
    p = strchr(a[i], 'E');
    if (p != NULL) {
      ey = p - a[i];
      ex = i;
    }
  }
  memset(lk, -1, sizeof(lk));
  queue<node> q;
  q.push({x, y, k, 0, 0});
  q.push({x, y, k, 1, 0});
  bool ok = 0;
  while (!q.empty()) {
    node t = q.front();
    q.pop();
    if (t.k < 0)
      continue;
    if (t.x == ex && t.y == ey) {
      cout << t.d << "\n";
      ok = 1;
      break;
    }
    if (lk[t.x][t.y][t.o] >= t.k)
      continue;
    lk[t.x][t.y][t.o] = t.k;
    if (t.o == 0) {
      if (t.x < n - 1) {
        int tk = t.k;
        if (a[t.x + 1][t.y] == '*')
          tk--;
        if (tk >= 0)
          q.push({t.x + 1, t.y, tk, t.o ^ 1, t.d + 1});
      }
      if (t.x > 0) {
        int tk = t.k;
        if (a[t.x - 1][t.y] == '*')
          tk--;
        if (tk >= 0)
          q.push({t.x - 1, t.y, tk, t.o ^ 1, t.d + 1});
      }
    } else {
      if (t.y < m - 1) {
        int tk = t.k;
        if (a[t.x][t.y + 1] == '*')
          tk--;
        if (tk >= 0)
          q.push({t.x, t.y + 1, tk, t.o ^ 1, t.d + 1});
      }
      if (t.y > 0) {
        int tk = t.k;
        if (a[t.x][t.y - 1] == '*')
          tk--;
        if (tk >= 0)
          q.push({t.x, t.y - 1, tk, t.o ^ 1, t.d + 1});
      }
    }
  }
  if (!ok)
    cout << -1 << "\n";
  return 0;
}