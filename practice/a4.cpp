#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[10005];
int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++)
    cin >> a[i];
  if (k == 1)
    cout << "yes\n";
  else {
    vector<pair<int, int>> prem;
    int t = a[1];
    for (int i = 2; i * i <= t; i++)
      if (t % i == 0) {
        int cnt = 0;
        while (t % i == 0) {
          cnt++;
          t /= i;
        }
        prem.push_back({i, cnt});
      }
    if (t > 1)
      prem.push_back({t, 1});
    bool ok = true;
    for (auto [p, need] : prem) {
      for (int i = 0; i < k; i++)
        if (i != 1) {
          int t = a[i];
          while (t % p == 0) {
            need--;
            t /= p;
          }
          if (need <= 0)
            break;
        }
      if (need > 0) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "yes\n" : "no\n");
  }
}