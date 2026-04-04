#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n, m;
  cin >> n >> m;
  int k = sqrt(m + 0.5);
  vector<bool> vis(k + 1);
  for (int i = 2; i * i <= k; i++)
    if (!vis[i])
      for (int j = i * i; j <= k; j += i)
        vis[j] = true;
  vector<bool> vis2(m - n + 1);
  int cnt = 0;
  for (ll i = 2; i <= k; i++)
    if (!vis[i])
      for (ll j = ((n - 1) / (i * i) + 1) * i * i; j <= m; j += i * i)
        if (!vis2[j - n]) {
          vis2[j - n] = true;
          cnt++;
        }
  cout << m - n + 1 - cnt << "\n";
  return 0;
}