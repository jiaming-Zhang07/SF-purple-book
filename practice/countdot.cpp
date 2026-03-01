#include <bits/stdc++.h>
using namespace std;
struct interval {
  int l, r;
  bool operator<(const interval &other) const {
    return r < other.r;
  }
};
int main() {
  int n;
  cin >> n;
  vector<interval> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].l >> v[i].r;
  sort(v.begin(), v.end());
  int cnt = 0;
  int dot = v[0].l - 1;
  for (int i = 0; i < n; i++) {
    if (v[i].l <= dot)
      continue;
    cnt++;
    dot = v[i].r;
  }
  cout << cnt;
  return 0;
}