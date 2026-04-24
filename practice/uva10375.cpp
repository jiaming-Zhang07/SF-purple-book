#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 10000;
int need[maxn + 5];
int main() {
  int p, q, r, s;
  vector<int> prem;
  int m = sqrt(maxn + 0.5);
  vector<bool> vis(maxn + 1);
  for (int i = 2; i <= m; i++)
    if (!vis[i])
      for (int j = i * i; j <= maxn; j += i)
        vis[j] = true;
  for (int i = 2; i <= maxn; i++)
    if (!vis[i])
      prem.push_back(i);
  while (cin >> p >> q >> r >> s) {
    vector<int> num(q + s);
    for (int i = 0; i < s; i++)
      num[i] = i + 1;
    for (int i = s, x = p - q + 1; i < q + s; i++, x++)
      num[i] = x;
    memset(need, 0, sizeof(need));
    for (int &t : num) {
      for (auto x : prem) {
        if (x * x > t)
          break;
        while (t % x == 0) {
          need[x]++;
          t /= x;
        }
      }
      if (t > 1)
        need[t]++;
    }
    vector<int> den(q + s);
    for (int i = 0; i < q; i++)
      den[i] = i + 1;
    for (int i = q, x = r - s + 1; i < q + s; x++, i++)
      den[i] = x;
    for (int &t : den) {
      for (auto x : prem) {
        if (x * x > t)
          break;
        while (t % x == 0) {
          need[x]--;
          t /= x;
        }
      }
      if (t > 1)
        need[t]--;
    }
    double ans = 1;
    for (int x = 2; x <= maxn; x++)
      if (need[x]) {
        int t = need[x];
        ans *= pow(x, t);
      }
    cout << fixed << setprecision(5) << ans << "\n";
  }
  return 0;
}