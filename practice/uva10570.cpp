#include <bits/stdc++.h>
using namespace std;
int a[505], f[505], temp[505];
int n;
int pd() {
  int tot = 0;
  memcpy(temp, a, sizeof(temp));
  for (int i = 1; i <= n; i++)
    if (temp[i] != f[i]) {
      for (int j = i + 1; j <= n; j++)
        if (temp[j] == f[i]) {
          swap(temp[i], temp[j]);
          tot++;
          break;
        }
    }
  return tot;
}
void rotate() {
  memcpy(temp, f, sizeof(f));
  for (int i = 1; i <= n; i++)
    f[i == n ? 1 : i + 1] = temp[i];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (cin >> n && n) {
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= n; i++)
      f[i] = i;
    int ans = n;
    for (int i = 0; i < n; i++) {
      ans = min(ans, pd());
      rotate();
    }
    for (int i = 0; i < n; i++)
      f[i] = n - i;
    for (int i = 0; i < n; i++) {
      ans = min(ans, pd());
      rotate();
    }
    cout << ans << "\n";
  }
  return 0;
}