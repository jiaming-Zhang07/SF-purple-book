#include <bits/stdc++.h>
using namespace std;
struct interval {
  double l, r;
  bool operator<(const interval &other) const {
    return r < other.r;
  }
} a[100000];
int main() {
  int L, d, n;
  double x, y;
  while (cin >> L) {
    cin >> d >> n;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      double t = sqrt(d * d - y * y);
      a[i].l = x - t;
      a[i].r = x + t;
    }
    sort(a, a + n);
    int cnt = 1, last = a[0].r;
    for (int i = 1; i < n; i++)
      if (last < a[i].l) {
        cnt++;
        last = a[i].r;
      }
    printf("%d\n", cnt);
  }
  return 0;
}