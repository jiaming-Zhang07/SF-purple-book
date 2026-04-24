#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[100005];
struct sta {
  ll g, pos;
  bool operator<(const sta &b) const {
    return tie(g, pos) < tie(b.g, b.pos);
  }
};
ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<sta> v;
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < v.size(); i++)
        v[i].g = gcd(v[i].g, a[j]);
      v.push_back({a[j], j});
      sort(v.begin(), v.end());
      vector<sta> nv;
      for (int i = 0; i < v.size(); i++)
        if (i == 0 || v[i].g != v[i - 1].g) {
          nv.push_back(v[i]);
          ans = max(ans, v[i].g * (j - v[i].pos + 1));
        }
      v = nv;
    }
    cout << ans << "\n";
  }
  return 0;
}