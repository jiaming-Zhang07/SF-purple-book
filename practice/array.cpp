#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[300005];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  ll sum = 0;
  ll kk = 0;
  for (int i = 0; i < n; i++) {
    if (kk + a[i] > k) {
      int cnt = k - a[i];
      sum += (a[i] + a[i] - cnt + 1) * cnt / 2;
      break;
    }
    sum += (a[i] + 1) * a[i] / 2;
    kk += a[i];
  }
  cout << sum << "\n";
  return 0;
}