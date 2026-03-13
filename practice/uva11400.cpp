#include <bits/stdc++.h>
using namespace std;
struct lamp {
  int v, k, c, l;
  bool operator<(const lamp &other) const {
    return v < other.v;
  }
} a[1005];
int s[1005], d[1005];
int main() {
  int n;
  while (cin >> n && n) {
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].v >> a[i].k >> a[i].c >> a[i].l;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
      s[i] = s[i - 1] + a[i].l;
    for (int i = 1; i <= n; i++) {
      d[i] = s[i] * a[i].c + a[i].k;
      for (int j = 1; j < i; j++)
        d[i] = min(d[i], d[j] + (s[i] - s[j]) * a[i].c + a[i].k);
    }
    cout << d[n] << "\n";
  }
  return 0;
}