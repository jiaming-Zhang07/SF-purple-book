#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
const int maxn = 100005;
const ld eps = 1e-10;
struct interval {
  int l, r;
  bool operator<(const interval &other) {
    return tie(l, r) < tie(other.l, other.r);
  }
} a[maxn];
int n;
bool check(long double len) {
  long double cur = a[0].l;
  for (int i = 0; i < n; i++) {
    cur = max(cur, (ld)a[i].l);
    cur += len;
    if (cur > a[i].r)
      return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      cin >> a[i].l >> a[i].r;
    sort(a, a + n);
    long double L = 0, R = 1000000;
    int t = 0;
    while (t++ < 100) {
      long double m = L + (R - L) / 2.0;
      if (check(m))
        L = m;
      else
        R = m;
    }
    ld mind = 1, ans = L;
    int anq, anp;
    for (int q = 1; q <= n; q++) {
      ll p = q * ans + 0.5 + eps;
      if (abs((ld)p / q - ans) < mind) {
        anq = q;
        anp = p;
        mind = abs((ld)p / q - ans);
      }
    }
    int g = __gcd(anp, anq);
    cout << anp / g << "/" << anq / g << "\n";
  }
  return 0;
}