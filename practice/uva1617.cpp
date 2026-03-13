#include <bits/stdc++.h>
using namespace std;
struct interval {
  int l, r;
  bool operator<(const interval &other) const {
    return tie(l, r) < tie(other.l, other.r);
  }
} a[100005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 0) {
      cout << 0 << "\n";
      continue;
    }
    for (int i = 0; i < n; i++)
      cin >> a[i].l >> a[i].r;
    sort(a, a + n);
    int end = a[0].r, ans = 0;
    for (int i = 1; i < n; i++) {
      if (a[i].l > end) {
        ans++;
        end = a[i].r;
      } else if (a[i].r > end)
        end++;
    }
    cout << ans << "\n";
  }
  return 0;
}