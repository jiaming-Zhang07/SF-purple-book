#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, ll, greater<ll>> mp;
int main() {
  int n, k;
  cin >> n >> k;
  int val;
  for (int i = 0; i < n; i++) {
    cin >> val;
    mp[val]++;
  }
  int kk = 0;
  ll sum = 0;
  mp[0] = 1;
  auto t = mp.begin();
  for (;;) {
    auto it = t;
    t++;
    if (t == mp.end())
      break;
    if ((it->first - t->first) * it->second > k - kk) {
      for (int i = 0; i < it->first - t->first; i++) {
        if (it->second > k - kk) {
          sum += (it->first - i) * (k - kk);
          break;
        }
        sum += (it->first - i) * it->second;
        kk += it->second;
      }
      break;
    }
    sum += ((it->first + t->first) + 1) * (it->first - t->first) * it->second / 2;
    kk += it->second * (it->first - t->first);
    t->second += it->second;
  }
  cout << sum << "\n";
  return 0;
}