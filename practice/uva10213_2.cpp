#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
void print128(i128 t) {
  if (t == 0) {
    cout << "0\n";
    return;
  }
  string s;
  while (t) {
    s += (char)('0' + t % 10);
    t /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s << "\n";
}
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
    __int128_t t = n;
    t = 1 + t * (t - 1) * (t - 2) * (t - 3) / 24 + t * (t - 3) / 2 + t;
    print128(t);
  }
  return 0;
}