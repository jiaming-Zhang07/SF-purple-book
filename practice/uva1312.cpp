#include <bits/stdc++.h>
using namespace std;
struct pts {
  int x, y;
  bool operator<(const pts &other) const {
    return tie(x, y) < tie(other.x, other.y);
  }
} a[105];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> y(n + 2);
    for (int i = 0; i < n; i++) {
      cin >> a[i].x >> a[i].y;
      y[i] = a[i].y;
    }
    y[n] = 0;
    y[n + 1] = h;
    sort(a, a + n);
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    int maxl = 0, ansx, ansy;
    for (int i = 0; i < y.size(); i++)
      for (int j = i + 1; j < y.size(); j++) {
        if (y[j] - y[i] < maxl)
          continue;
        int h1 = y[j] - y[i];
        int last = 0;
        for (int k = 0; k < n; k++)
          if (a[k].y > y[i] && a[k].y < y[j]) {
            int w1 = a[k].x - last;
            int curl = min(w1, h1);
            if (curl > maxl) {
              ansx = last;
              ansy = y[i];
              maxl = curl;
            }
            last = a[k].x;
          }
        int w1 = w - last;
        int curl = min(w1, h1);
        if (curl > maxl) {
          ansx = last;
          ansy = y[i];
          maxl = curl;
        }
      }
    cout << ansx << " " << ansy << " " << maxl << "\n";
    if (T)
      cout << "\n";
  }
  return 0;
}