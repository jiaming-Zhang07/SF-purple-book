#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 40005, INF = 1 << 30;
int w[maxn], sum[maxn], min_even[maxn], min_odd[maxn];
int n, m, d;
bool check(int W) {
  min_even[0] = 0;
  min_odd[0] = INF;
  for (int i = 1; i <= n / 2; i++) {
    min_odd[i] = min_even[i] = INF;
    for (int j = i - 1; j >= max(0, i - d); j--) {
      int righ = sum[2 * i] - sum[i + j], lef = sum[i + j] - sum[2 * j];
      if (righ > W)
        break;
      if (lef <= W) {
        if (min_even[j] != INF)
          min_odd[i] = min(min_odd[i], min_even[j] + 1);
        if (min_odd[j] != INF)
          min_even[i] = min(min_even[i], min_odd[j] + 1);
      }
    }
  }
  return (m - 1) % 2 == 0 ? m - 1 >= min_even[n / 2] : m - 1 >= min_odd[n / 2];
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> d;
    int maxw = 0, max_w = 0;
    for (int i = 1; i <= n; i++) {
      cin >> w[i];
      sum[i] = sum[i - 1] + w[i];
      maxw = max(maxw, w[i]);
      max_w = max(max_w, sum[i] - sum[max(0, i - d)]);
    }
    if (n % 2 == 1 || n < (m - 1) * 2 || n > (m - 1) * 2 * d) {
      cout << "BAD\n";
      continue;
    }
    int L = maxw, R = max_w;
    while (L < R) {
      int mid = L + (R - L) / 2;
      if (check(mid))
        R = mid;
      else
        L = mid + 1;
    }
    cout << L << "\n";
  }
  return 0;
}