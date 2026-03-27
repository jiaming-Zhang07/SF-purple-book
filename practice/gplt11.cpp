#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 500005;
ll a[maxn], b[maxn], pre[maxn], suff[maxn];
ll f(ll n) {
  return abs(n * n * n);
}
int main() {
  int n, m;
  cin >> n >> m;
  if (n - 1 == 0 || m % (n - 1)) {
    cout << "failed.\n";
    return 0;
  }
  ll sum = 0;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  for (int i = 0; i < m; i += n - 1) {
    ll ans = 1LL << 60;
    for (int j = 1; j <= n - 1; j++)
      pre[j] = pre[j - 1] + f(a[j - 1] - b[i + j - 1]);
    for (int j = n - 1; j > 0; j--)
      suff[j] = suff[j + 1] + f(a[j] - b[i + j - 1]);
    for (int j = 1; j <= n; j++)
      ans = min(ans, pre[j - 1] + suff[j]);
    sum += ans;
  }
  cout << sum << "\n";
}