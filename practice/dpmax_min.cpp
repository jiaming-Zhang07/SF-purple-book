#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[10005], L[10005], R[10005];
int main() {
  int n;
  ll ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int t = i - 1;
    while (t > 0 && a[t] >= a[i])
      t = L[t];
    L[i] = t;
  }
  for (int i = n; i >= 1; i--) {
    int t = i + 1;
    while (t < n + 1 && a[t] >= a[i])
      t = R[t];
    R[i] = t;
  }
  for (int i = 1; i <= n; i++)
    ans = max(ans, (ll)(R[i] - L[i] - 1) * a[i]);
  cout << ans << "\n";
  return 0;
}