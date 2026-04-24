#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[200005];
int Q = 500;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    ll ans = 0;
    for (int i = 0; i < n; i++)
      if (a[i] > Q) {
        for (int k = 1; i + a[i] * k < n; k++)
          if (a[i + a[i] * k] == k)
            ans++;
        for (int k = 1; i - a[i] * k >= 0; k++)
          if (a[i - a[i] * k] == k)
            ans++;
      } else {
        for (int k = 1; i + k * a[i] < n && k <= Q; k++)
          if (a[i + k * a[i]] == k)
            ans++;
      }
    cout << ans << "\n";
  }
  return 0;
}