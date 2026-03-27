#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
ll a[300005];
bool check(int m) {
  ll cnt = 0;
  for (int i = 0; i < n; i++)
    if (a[i] >= m)
      cnt += a[i] - m + 1;
  return cnt >= k;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int l = 0, r = 1 << 30;
  while (l < r) {
    int mid = l + (r - l + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else
      r = mid - 1;
  }
  ll sum = 0;
  for (int i = 0; i < n; i++)
    if (a[i] > l) {
      sum += (a[i] - l) * (a[i] + l + 1) / 2;
      k -= a[i] - l;
    }
  sum += (ll)k * l;
  cout << sum << "\n";
  return 0;
}