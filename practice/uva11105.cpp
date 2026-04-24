#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 250000;
bool vis[maxn + 5];
int sum[maxn + 5];
int main() {
  int h;
  vector<int> v;
  for (ll i = 1; i <= maxn; i++)
    if (!vis[i]) {
      v.push_back(i);
      for (ll j = i; 4 * i * j + i + j <= maxn; j++)
        vis[4 * i * j + i + j] = true;
    }
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < v.size(); i++)
    for (int j = i; j < v.size(); j++) {
      ll p1 = v[i], p2 = v[j];
      ll temp = 4 * p1 * p2 + p1 + p2;
      if (temp > maxn)
        break;
      if (!vis[temp]) {
        vis[temp] = true;
        sum[temp]++;
      }
    }
  for (int i = 1; i <= maxn; i++)
    sum[i] += sum[i - 1];
  while (cin >> h && h)
    cout << h << " " << sum[h / 4] << "\n";
  return 0;
}