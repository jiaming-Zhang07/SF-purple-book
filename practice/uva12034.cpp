#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 10056;
int f[1001], c[1001][1001];
void init() {
  c[0][0] = 1;
  for (int n = 1; n <= 1000; n++) {
    c[n][0] = 1;
    for (int i = 1; i <= n; i++)
      c[n][i] = (c[n - 1][i - 1] + c[n - 1][i]) % mod;
  }
  f[0] = 1;
  f[1] = 1;
  for (int n = 2; n <= 1000; n++) {
    for (int k = 1; k <= n; k++) {
      f[n] = (f[n] + c[n][k] * f[n - k]) % mod;
    }
  }
}
int main() {
  int T, kase = 0;
  init();
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    printf("Case %d: %d\n", ++kase, f[n]);
  }
  return 0;
}