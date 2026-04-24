#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using i128 = __int128;
vector<int> v;
bool vis[100];
i128 c[65][65];
ll n;
ll ans;
const ll maxk = 1ull << 63;
void dfs(int idx, ll curk, i128 cur, int cnt, int limit) {
  if (cur > n)
    return;
  if (cur == n) {
    ans = min(ans, curk);
    return;
  }
  if (idx >= v.size() || (i128)curk * v[idx] >= maxk)
    return;
  for (int i = 1; i <= 63; i++) {
    if (curk > (maxk - 1) / v[idx] || i > limit)
      break;
    curk *= v[idx];
    dfs(idx + 1, curk, cur * c[cnt + i][i], cnt + i, i);
  }
}
int main() {
  for (int i = 2; i <= 100; i++)
    if (!vis[i]) {
      v.push_back(i);
      for (int j = i * i; j <= 100; j += i)
        vis[j] = true;
    }
  c[0][0] = 1;
  for (int i = 1; i <= 64; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = c[i][j - 1] * (i - j + 1) / j;
  }
  while (cin >> n) {
    ans = maxk;
    if (n == 1) {
      cout << n << " " << 2 << "\n";
      continue;
    }
    dfs(0, 1, 1, 0, 65);
    cout << n << " " << ans << "\n";
  }
  return 0;
}