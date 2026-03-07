#include <bits/stdc++.h>
using namespace std;
int n, target[505], pos[505], vis[505], a[505];
int Min() {
  int cir = 0;
  for (int i = 0; i < n; i++)
    pos[target[i]] = i;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++)
    if (!vis[i]) {
      cir++;
      int cur = i;
      while (!vis[cur]) {
        vis[cur] = 1;
        cur = pos[a[cur]];
      }
    }
  return n - cir;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (cin >> n && n) {
    int ans = n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int k = 0; k < n; k++) {
      for (int j = 0; j < n; j++)
        target[j] = (k + j) % n + 1;
      ans = min(ans, Min());
      for (int j = 0; j < n; j++)
        target[j] = (n + k - j) % n + 1;
      ans = min(ans, Min());
    }
    cout << ans << "\n";
  }
  return 0;
}