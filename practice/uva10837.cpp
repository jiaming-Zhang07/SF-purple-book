#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e4;
vector<int> v;
bool vis[maxn + 1];
#define int long long
int ans;
void dfs(int cur, int phi, int pos) {
  if (phi == 1) {
    ans = min(ans, cur);
    return;
  }
  bool ok = true;
  for (int i = 0; i < v.size() && v[i] * v[i] <= phi + 1; i++)
    if ((phi + 1) % v[i] == 0) {
      ok = false;
      break;
    }
  if (ok && (pos == 0 || v[pos - 1] < phi + 1)) {
    ans = min(cur * (phi + 1), ans);
  }
  for (int i = pos; i < v.size(); i++) {
    if (v[i] - 1 > phi)
      break;
    if (phi % (v[i] - 1) == 0) {
      int temp = cur * v[i], temp_phi = phi / (v[i] - 1);
      dfs(temp, temp_phi, i + 1);
      while (temp_phi % v[i] == 0) {
        temp *= v[i];
        temp_phi /= v[i];
        dfs(temp, temp_phi, i + 1);
      }
    }
  }
}
signed main() {
  for (int i = 2; i <= maxn; i++)
    if (!vis[i]) {
      v.push_back(i);
      for (int j = i * i; j <= maxn; j += i)
        vis[j] = true;
    }
  signed kase = 0, m;
  while (cin >> m && m) {
    ans = 1 << 30;
    dfs(1, m, 0);
    printf("Case %d: %d %lld\n", ++kase, m, ans);
  }
  return 0;
}