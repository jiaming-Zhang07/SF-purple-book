#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[4];
int main() {
  ll n, m;
  int kase = 0;
  while (scanf("%lld%lld", &n, &m) == 2 && (n || m)) {
    ll sum = 0;
    for (int i = 0; i < 4; i++)
      scanf("%d", &a[i]);
    ll a1 = min(a[0], a[1]), a2 = min(a[2], a[3]);
    ll b1 = max(a[0], a[1]) - a1, b2 = max(a[2], a[3]) - a2;
    while (m > 0 && n > 0) {
      int type = 0, type2 = 0;
      ll pv = -1, ph = -1;
      if (a1 > 0) {
        if (b1) {
          pv = (n - 1) * a1 * 2 + n;
          type = 1;
        } else {
          pv = (n - 1) * (2 * a1 - 1) + n;
          type = 2;
        }
      } else if (b1 > 0) {
        pv = n;
        type = 3;
      }
      if (a2 > 0) {
        if (b2) {
          ph = (m - 1) * a2 * 2 + m;
          type2 = 1;
        } else {
          ph = (m - 1) * (2 * a2 - 1) + m;
          type2 = 2;
        }
      } else if (b2 > 0) {
        ph = m;
        type2 = 3;
      }
      if (type == 0 && type2 == 0)
        break;
      if (pv >= ph) {
        if (type == 1) {
          sum += n * m + 2 * a1 * (n - 1) * m;
          b1--;
          a1 = 0;
        } else if (type == 2) {
          sum += n * m + (2 * a1 - 1) * (n - 1) * m;
          a1 = 0;
        } else if (type == 3) {
          sum += n * m;
          b1--;
        }
        n--;
      } else {
        if (type2 == 1) {
          sum += n * m + 2 * a2 * (m - 1) * n;
          b2--;
          a2 = 0;
        } else if (type2 == 2) {
          sum += n * m + (2 * a2 - 1) * (m - 1) * n;
          a2 = 0;
        } else if (type2 == 3) {
          sum += n * m;
          b2--;
        }
        m--;
      }
    }
    printf("Case %d: %lld\n", ++kase, sum);
  }
  return 0;
}