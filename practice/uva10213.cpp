#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct bigint {
  vector<int> v;
  static const int base = 1e8;
  bigint(ll a = 0) {
    if (a == 0) {
      v.push_back(0);
      return;
    }
    while (a) {
      v.push_back(a % base);
      a /= base;
    }
  }
  void trim() {
    while (v.size() > 1 && v.back() == 0)
      v.pop_back();
  }
  bigint &operator*=(ll a) {
    ll c = 0;
    for (int i = 0; i < v.size() || c; i++) {
      if (i == (int)v.size())
        v.push_back(0);
      ll temp = 1ll * v[i] * a + c;
      v[i] = temp % base;
      c = temp / base;
    }
    trim();
    return *this;
  }
  bigint &operator+=(ll a) {
    ll c = a;
    for (int i = 0; c; i++) {
      if (i == (int)v.size())
        v.push_back(0);
      ll temp = v[i] + c;
      c = temp / base;
      v[i] = temp % base;
    }
    return *this;
  }
  bigint &operator/=(ll a) {
    ll c = 0;
    for (int i = (int)v.size() - 1; i >= 0; i--) {
      ll temp = 1ll * v[i] + c * base;
      c = temp % a;
      v[i] = temp / a;
    }
    trim();
    return *this;
  }
  bool operator<(const bigint &b) const {
    if (v.size() != b.v.size())
      return v.size() < b.v.size();
    for (int i = (int)v.size() - 1; i >= 0; i--)
      if (v[i] != b.v[i])
        return v[i] < b.v[i];
    return false;
  }
  bool operator==(const bigint &b) const {
    return v == b.v;
  }
  bigint operator*(const bigint &b) const {
    bigint res;
    res.v.assign(v.size() + b.v.size(), 0);
    for (int i = 0; i < v.size(); i++) {
      ll c = 0;
      for (int j = 0; j < b.v.size() || c; j++) {
        ll cur = res.v[i + j] + 1ll * v[i] * (j < b.v.size() ? b.v[j] : 0) + c;
        c = cur / base;
        res.v[i + j] = cur % base;
      }
    }
    res.trim();
    return res;
  }
  void output() const {
    if (v.empty()) {
      printf("0\n");
      return;
    }
    printf("%d", v.back());
    for (int i = (int)v.size() - 2; i >= 0; i--)
      printf("%08d", v[i]);
    printf("\n");
  }
};
int main() {
  ll n, T;
  cin >> T;
  while (T--) {
    cin >> n;
    if (n <= 3) {
      if (n == 1 || n == 0)
        cout << "1\n";
      else if (n == 2)
        cout << "2\n";
      else
        cout << "4\n";
      continue;
    }
    bigint ans(n);
    for (int i = 1; i <= 3; i++)
      ans *= n - i;
    (ans /= 24) += 1 + n + n * (n - 3) / 2;
    ans.output();
  }
  return 0;
}