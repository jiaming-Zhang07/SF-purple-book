#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}
void output(int len, char c) {
  while (len--)
    cout << c;
}
int main() {
  int n;
  while (cin >> n) {
    if (n == 1) {
      cout << n << "\n";
      continue;
    }
    ll den = 1;
    for (int i = 2; i <= n - 1; i++)
      den = lcm(den, i);
    ll num = 0;
    for (int i = 2; i <= n - 1; i++)
      num += den / i;
    num *= n;
    ll d = gcd(num, den);
    num /= d;
    den /= d;
    ll inte = n + 1 + num / den;
    num %= den;
    if (num == 0)
      cout << inte << "\n";
    else {
      int len = to_string(inte).size();
      output(len + 1, ' ');
      cout << num << "\n";
      cout << inte << " ";
      output(to_string(den).size(), '-');
      cout << "\n";
      output(len + 1, ' ');
      cout << den << "\n";
    }
  }
  return 0;
}