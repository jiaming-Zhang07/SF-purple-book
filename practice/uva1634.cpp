#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct point {
  int x, y;
  point operator-(const point &o) const {
    return {x - o.x, y - o.y};
  }
} p[105];
int cross(const point &p1, const point &p2) {
  return p1.x * p2.y - p1.y * p2.x;
}
int dist2(const point &p1, const point &p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
int main() {
  int T;
  int m;
  cin >> T;
  while (T--) {
    cin >> m;
    for (int i = 0; i < m; i++)
      cin >> p[i].x >> p[i].y;
    int ans2 = 0;
    for (int i = 0; i < m; i++) {
      point s = p[i];
      vector<point> v;
      for (int j = 0; j < m; j++)
        if (j != i && (p[j].y > s.y || (p[j].y == s.y && p[j].x > s.x)))
          v.push_back(p[j]);
      sort(v.begin(), v.end(), [&](const point &p1, const point &p2) {
        return cross(p1 - s, p2 - s) > 0;
      });
      int n = v.size();
      if (n < 2)
        continue;
      vector<vector<bool>> ok(n, vector<bool>(n, true));
      auto inside = [&](const point &p1, const point &p2, const point &x) {
        return cross(p1 - s, x - s) > 0 && cross(p2 - p1, x - p1) > 0 && cross(s - p2, x - p2) > 0;
      };
      for (int j = 0; j < n; j++)
        for (int k = j + 1; k < n; k++)
          for (int x = 0; x < n; x++)
            if (inside(v[j], v[k], v[x])) {
              ok[j][k] = false;
              break;
            }
      vector<bool> have_inside_dot(n, false);
      for (int j = 0; j < n; j++)
        for (int x = 0; x < n; x++)
          if (j != x && (v[j].x - s.x) * (v[x].x - s.x) + (v[j].y - s.y) * (v[x].y - s.y) > 0 && cross(v[j] - s, v[x] - s) == 0 && dist2(v[j], s) > dist2(v[x], s))
            have_inside_dot[j] = true;
      vector<vector<int>> dp(n, vector<int>(n, -1));
      for (int j = 0; j < n; j++)
        for (int k = j + 1; k < n; k++) {
          if (cross(v[j] - s, v[k] - s) == 0 || !ok[j][k])
            continue;
          int cur_area = cross(v[j] - s, v[k] - s);
          dp[j][k] = cur_area;
          for (int x = 0; x < j; x++)
            if (dp[x][j] != -1 && !have_inside_dot[j] && cross(v[j] - v[x], v[k] - v[j]) > 0)
              dp[j][k] = max(dp[j][k], dp[x][j] + cur_area);
          ans2 = max(ans2, dp[j][k]);
        }
    }
    cout << fixed << setprecision(1) << ans2 / 2.0 << "\n";
  }
  return 0;
}