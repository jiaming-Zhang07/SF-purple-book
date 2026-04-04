#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
  if (b == 0) {
    d = a;
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, d, y, x);
  y -= a / b * x;
}
ll _ceil(ll num, ll den) {
  if (num >= 0)
    return (num + den - 1) / den;
  return num / den;
}
ll _floor(ll num, ll den) {
  if (num >= 0)
    return num / den;
  return (num + 1 - den) / den;
}
int main() {
  ll a, b, c, x1, x2, y1, y2;
  cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
  ll x, y, d;
  c = -c;
  if (!a && !b) {
    if (!c)
      cout << (x2 - x1 + 1) * (y2 - y1 + 1) << "\n";
    else
      cout << "0\n";
  } else if (!a) {
    if (c % b == 0 && c / b >= y1 && c / b <= y2)
      cout << x2 - x1 + 1 << "\n";
    else
      cout << "0\n";
  } else if (!b) {
    if (c % a == 0 && c / a >= x1 && c / a <= x2)
      cout << y2 - y1 + 1 << "\n";
    else
      cout << "0\n";
  } else {
    if (a < 0) {
      a = -a;
      x1 = -x1;
      x2 = -x2;
      swap(x1, x2);
    }
    if (b < 0) {
      b = -b;
      y1 = -y1;
      y2 = -y2;
      swap(y1, y2);
    }
    exgcd(a, b, d, x, y);
    if (c % d) {
      cout << "0\n";
      return 0;
    }
    x *= c / d;
    y *= c / d;
    ll mink = _ceil(x1 - x, b / d), maxk = _floor(x2 - x, b / d);
    maxk = min(maxk, _floor(y - y1, a / d));
    mink = max(mink, _ceil(y - y2, a / d));
    cout << max(0ll, maxk - mink + 1) << "\n";
  }
  return 0;
}