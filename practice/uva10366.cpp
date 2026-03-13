#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[1005], h[2][1005], highl[1005], highr[1005];
int main() {
  int l, r;
  while (scanf("%d%d", &l, &r) == 2 && l) {
    int n = (r - l) / 2 + 1, cntl = (-l + 1) / 2, cntr = n - cntl;
    ll sum = 0;
    for (int i = 0; i < n; i++)
      scanf("%lld", &a[i]);
    int maxl = *max_element(a, a + cntl), maxr = *max_element(a + cntl, a + n);
    for (int i = cntl - 1; i >= 0; i--)
      h[0][cntl - 1 - i] = a[i];
    for (int i = cntl; i < n; i++)
      h[1][i - cntl] = a[i];
    highl[cntl] = highr[cntr] = 0;
    for (int i = cntl - 1; i >= 0; i--)
      highl[i] = max(highl[i + 1], h[0][i]);
    for (int i = cntr - 1; i >= 0; i--)
      highr[i] = max(highr[i + 1], h[1][i]);
    int h0 = min(maxl, maxr);
    int idxl = 0;
    while (h[0][idxl] < h0)
      idxl++;
    int idxr = 0;
    while (h[1][idxr] < h0)
      idxr++;
    sum += h0 * (idxr + idxl + 1) * 2;
    if (h[0][idxl] > h[1][idxr]) {
      for (int i = idxr + 1; i < cntr; i++) {
        sum += highr[i] * 2;
      }
    } else if (h[0][idxl] < h[1][idxr]) {
      for (int i = idxl + 1; i < cntl; i++)
        sum += highl[i] * 2;
    } else {
      if (maxl != maxr) {
        if (maxl > maxr) {
          int t = idxl + 1;
          while (h[0][t] <= h[0][idxl])
            t++;
          ll sum2 = h[0][idxl] * 2 * (t - idxl);
          ll sum3 = 0;
          for (int i = idxr + 1; i < cntr; i++) {
            sum3 += highr[i] * 2;
          }
          if (sum3 <= sum2)
            sum += 2 * sum3;
          else
            sum += sum3 + sum2;
        } else {
          int t = idxr + 1;
          while (h[1][t] <= h[1][idxr])
            t++;
          ll sum2 = h[1][idxr] * 2 * (t - idxr);
          ll sum3 = 0;
          for (int i = idxl + 1; i < cntl; i++) {
            sum3 += highl[i] * 2;
          }
          if (sum3 <= sum2)
            sum += 2 * sum3;
          else
            sum += sum3 + sum2;
        }
      } else {
        ll sum1 = 0;
        for (int i = idxl + 1; i < cntl; i++) {
          sum1 += highl[i] * 2;
        }
        ll sum2 = 0;
        for (int i = idxr + 1; i < cntr; i++) {
          sum2 += highr[i] * 2;
        }
        sum += 2 * min(sum2, sum1);
      }
    }
    printf("%lld\n", sum);
  }
  return 0;
}