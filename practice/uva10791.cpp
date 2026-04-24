#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int kase = 0, n;
  while (cin >> n && n) {
    if (n == 1) {
      printf("Case %d: 2\n", ++kase);
      continue;
    }
    ll sum = 0;
    int cnt = 0;
    int m = sqrt(n + 0.5);
    for (int i = 2; i <= m; i++)
      if (n % i == 0) {
        cnt++;
        int b = 1;
        while (n % i == 0) {
          b *= i;
          n /= i;
        }
        sum += b;
        if (n == 1)
          break;
      }
    if (n > 1) {
      sum += n;
      cnt++;
    }
    if (cnt == 1)
      sum += 1;
    printf("Case %d: %lld\n", ++kase, sum);
  }
  return 0;
}