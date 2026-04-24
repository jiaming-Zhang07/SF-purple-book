#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n, d, kase = 0;
  while (cin >> n >> d && (n || d)) {
    double ans = d;
    for (int i = 0; i < n; i++) {
      int p, l, v;
      cin >> p >> l >> v;
      ans += 2.0 * l / (double)v - l;
    }
    printf("Case %d: %.3f\n\n", ++kase, ans);
  }
  return 0;
}