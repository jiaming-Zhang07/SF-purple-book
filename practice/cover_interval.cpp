#include <bits/stdc++.h>
using namespace std;
struct interval {
  int l, r;
  bool operator<(const interval &other) const {
    return l < other.l;
  }
};
int main() {
  int n, s, t;
  cin >> s >> t;
  cin >> n;
  vector<interval> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].l >> v[i].r;
  sort(v.begin(), v.end());
  int i = 0, ok = 1, cnt = 0, flag = 0;
  while (i < n) {
    ok = 0;
    int maxr = v[i].r;
    while (i < n && v[i].l <= s) {
      ok = 1;
      if (v[i].r > maxr)
        maxr = v[i].r;
      i++;
    }
    if (!ok || maxr <= s)
      break;
    s = maxr;
    cnt++;
    if (s >= t) {
      flag = 1;
      break;
    }
  }
  if (flag)
    cout << cnt << endl;
  else
    cout << -1 << endl;
  return 0;
}