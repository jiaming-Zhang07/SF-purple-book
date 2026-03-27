#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
  int a;
  int n;
  cin >> n;
  map<int, int> p;
  for (int i = 0; i < n; i++) {
    cin >> a;
    for (int j = 2; j * j <= a; j++) {
      if (a % j)
        continue;
      int cnt = 0;
      while (a % j == 0) {
        a /= j;
        cnt++;
      }
      p[j] = max(cnt, p[j]);
    }
    p[a] = max(p[a], 1);
  }
  int ans = 1;
  for (auto x : p) {
    ans *= (long long)pow(x.first, x.second) % mod;
  }
  cout << ans << "\n";
  return 0;
}