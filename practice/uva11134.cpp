#include <bits/stdc++.h>
using namespace std;
struct pos {
  int l, r, ans;
} x[5005], y[5005];
bool solve(pos *a, int n) {
  for (int pos = 1; pos <= n; pos++) {
    int rook;
    int minr = n + 1;
    for (int i = 0; i < n; i++)
      if (!a[i].ans && a[i].l <= pos && a[i].r < minr) {
        rook = i;
        minr = a[i].r;
      }
    if (minr == n + 1 || pos > minr)
      return false;
    a[rook].ans = pos;
  }
  return true;
}
int main() {
  int n;
  while (cin >> n && n) {
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    for (int i = 0; i < n; i++) {
      cin >> x[i].l >> y[i].l >> x[i].r >> y[i].r;
    }
    if (solve(x, n) && solve(y, n)) {
      for (int i = 0; i < n; i++)
        printf("%d %d\n", x[i].ans, y[i].ans);
    } else
      printf("IMPOSSIBLE\n");
  }
  return 0;
}