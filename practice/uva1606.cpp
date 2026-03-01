#include <bits/stdc++.h>
using namespace std;
struct dot {
  int x, y;
  int get_half() const {
    if (y > 0 || (y == 0 && x > 0))
      return 1;
    return 0;
  }
  bool operator<(const dot &other) const {
    if (get_half() != other.get_half())
      return get_half() > other.get_half();
    return x * other.y - y * other.x > 0;
  }
} op[1005], p[1005];
bool lef(const dot &t1, const dot &t2) {
  return t1.x * t2.y - t1.y * t2.x >= 0;
}
int n, color[1005];
int main() {
  while (cin >> n && n) {
    if (n == 1) {
      printf("1\n");
      continue;
    }
    for (int i = 0; i < n; i++)
      cin >> op[i].x >> op[i].y >> color[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int k = 0;
      for (int j = 0; j < n; j++)
        if (j != i) {
          p[k].x = op[j].x - op[i].x;
          p[k].y = op[j].y - op[i].y;
          if (color[j]) {
            p[k].x = -p[k].x;
            p[k].y = -p[k].y;
          }
          k++;
        }
      sort(p, p + k);
      int l = 0, r = 0, cnt = 2;
      while (l < k) {
        if (l == r) {
          r = (r + 1) % k;
          cnt++;
        }
        while (l != r && lef(p[l], p[r])) {
          r = (r + 1) % k;
          cnt++;
        }
        cnt--;
        l++;
        ans = max(ans, cnt);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}