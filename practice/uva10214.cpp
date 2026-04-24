#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll phi[2000001];
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}
int main() {
  phi[1] = 1;
  for (int i = 2; i <= 2000000; i++)
    if (!phi[i])
      for (int j = i; j <= 2000000; j += i) {
        if (!phi[j])
          phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
  int a, b;
  while (cin >> a >> b && a) {
    ll ans = 0;
    for (int i = 1; i <= a; i++) {
      ans += (b / i) * phi[i];
      for (int j = 1; j <= b - (b / i) * i; j++)
        if (gcd(j, i) == 1)
          ans++;
    }
    ans = ans * 4 + 4;
    cout << fixed << setprecision(7) << (double)ans / ((2ll * a + 1) * (2ll * b + 1) - 1) << "\n";
  }
  return 0;
}