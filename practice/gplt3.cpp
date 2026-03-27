#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  long long ans = 0;
  cin >> n >> m;
  int now = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x, y;
  while (a[now] == 0)
    now++;
  for (int i = 0; i < m; i++) {
    if (now == n)
      break;
    cin >> x >> y;
    while (x >= a[now]) {
      if (now == n)
        break;
      x -= a[now];
      now++;
      ans += y;
    }
    a[now] -= x;
  }
  cout << ans << "\n";
  return 0;
}