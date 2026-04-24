#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 100000007;
bool vis[10000005];
ll phifac[10000005];
int main() {
  int n, m;
  for (int i = 2; i * i <= 10000000; i++)
    if (!vis[i])
      for (int j = i * i; j <= 10000000; j += i)
        vis[j] = true;
  phifac[1] = 1;
  for (int i = 2; i <= 10000000; i++)
    phifac[i] = ((vis[i] ? i : i - 1) * phifac[i - 1]) % mod;
  while (cin >> n >> m && n) {
    ll ans = 1;
    for (int i = m + 1; i <= n; i++)
      ans = (ans * i) % mod;
    ans = (ans * phifac[m]) % mod;
    cout << ans - 1 << "\n";
  }
  return 0;
}