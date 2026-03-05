#include <bits/stdc++.h>
using namespace std;
struct sta {
  int a, g;
  bool operator<(const sta &other) const {
    return a < other.a;
  }
};
int A[200005], g[200005], f[200005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int ans = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> A[i];
    g[0] = 1;
    for (int i = 1; i < n; i++)
      if (A[i] > A[i - 1])
        g[i] = g[i - 1] + 1;
      else
        g[i] = 1;
    f[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
      if (A[i] < A[i + 1])
        f[i] = f[i + 1] + 1;
      else
        f[i] = 1;
    set<sta> s;
    s.insert({A[0], g[0]});
    for (int i = 1; i < n; i++) {
      sta c = {A[i], g[i]};
      auto it = s.upper_bound(c);
      auto it2 = s.lower_bound(c);
      if (it2 != s.begin()) {
        ans = max(ans, f[i] + (*(--it2)).g);
      } else
        ans = max(ans, f[i]);
      bool keep = true;
      if (it != s.begin() && (*(--it)).g >= c.g)
        keep = false;
      if (keep) {
        s.erase(c);
        s.insert(c);
        auto it = s.find(c);
        it++;
        while (it != s.end() && (*it).g <= c.g) {
          s.erase(it++);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}