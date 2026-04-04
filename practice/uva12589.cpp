#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct vec {
  int x, y;
  bool operator<(const vec &other) const {
    return x * other.y < other.x * y;
  }
};
const int maxn = 55;
int d[maxn][maxn * maxn];
int main() {
  int T, kase = 0;
  cin >> T;
  while (T--) {
    memset(d, -1, sizeof(d));
    int n, k;
    cin >> n >> k;
    vector<vec> v(n);
    int sumh = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i].x >> v[i].y;
      sumh += v[i].y;
    }
    sort(v.begin(), v.end());
    d[0][0] = 0;
    for (int i = 0; i < n; i++) {
      int x = v[i].x, y = v[i].y;
      for (int j = k; j > 0; j--)
        for (int h = sumh; h >= y; h--)
          if (d[j - 1][h - y] != -1) {
            d[j][h] = max(d[j][h], d[j - 1][h - y] + (h - y) * x * 2 + x * y);
          }
    }
    int ans = 0;
    for (int h = 0; h <= sumh; h++)
      ans = max(ans, d[k][h]);
    printf("Case %d: %d\n", ++kase, ans);
  }
  return 0;
}