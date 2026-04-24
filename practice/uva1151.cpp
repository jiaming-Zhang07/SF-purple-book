#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cost[10];
vector<int> v[10];
int x[1005], y[1005];
int n;
struct edge {
  int a, b, w;
  bool operator<(const edge &b) const {
    return w < b.w;
  }
};
int fa[1005];
int find(int a) {
  return fa[a] == a ? a : fa[a] = find(fa[a]);
}
int MST(int cnt, vector<edge> &sour, vector<edge> &used) {
  if (cnt == 0)
    return 0;
  int c = 0;
  for (int i = 0; i < sour.size(); i++) {
    int a = find(sour[i].a), b = find(sour[i].b);
    if (a != b) {
      used.push_back({a, b, sour[i].w});
      fa[a] = b;
      c += sour[i].w;
      if (--cnt == 0)
        break;
    }
  }
  return c;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int q;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
      int t;
      cin >> t;
      cin >> cost[i];
      v[i].resize(t);
      for (int j = 0; j < t; j++) {
        int temp;
        cin >> temp;
        v[i][j] = temp - 1;
      }
    }
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    vector<edge> e;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        int d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
        e.push_back({i, j, d});
      }
    for (int i = 0; i < n; i++)
      fa[i] = i;
    sort(e.begin(), e.end());
    vector<edge> need;
    int ans = MST(n - 1, e, need);
    for (int mask = 1; mask < 1 << q; mask++) {
      for (int i = 0; i < n; i++)
        fa[i] = i;
      int c = 0, cnt = n - 1;
      for (int i = 0; i < q; i++)
        if (1 << i & mask) {
          c += cost[i];
          for (int j = 1; j < v[i].size(); j++) {
            int a = find(v[i][j]), b = find(v[i][0]);
            if (a != b) {
              fa[a] = b;
              cnt--;
            }
          }
        }
      vector<edge> temp;
      ans = min(ans, c + MST(cnt, need, temp));
    }
    cout << ans << "\n";
    if (T)
      cout << "\n";
  }
  return 0;
}