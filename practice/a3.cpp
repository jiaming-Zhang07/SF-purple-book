#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[10005];
struct Bigint {
  vector<ll> digits;
  static const ll base = 1e9;
  Bigint(ll v) {
    if (v == 0)
      digits = {0};
    else {
      while (v > 0) {
        digits.push_back(v % base);
        v /= base;
      }
    }
  }
  void multiply(ll v) {
    ll carry = 0;
    for (int i = 0; i < digits.size() || carry; i++) {
      if (i == digits.size())
        digits.push_back(0);
      ll cur = digits[i] * v + carry;
      digits[i] = cur % base;
      carry = cur / base;
    }
  }
  ll rem(ll v) {
    ll r = 0;
    for (int i = (int)digits.size() - 1; i >= 0; i--) {
      r = (r * base + digits[i]) % v;
    }
    return r;
  }
};
int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++)
    cin >> a[i];
  if (k == 1)
    cout << "yes\n";
  else {
    Bigint b(a[0]);
    for (int i = 2; i < k; i++)
      b.multiply(a[i]);
    cout << (b.rem(a[1]) == 0 ? "yes" : "no") << "\n";
  }
  return 0;
}