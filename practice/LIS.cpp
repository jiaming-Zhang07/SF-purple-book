#include <bits/stdc++.h>
using namespace std;
int a[1005], d[1005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    d[i] = 1;
    for (int j = i - 1; j >= 0; j--)
      if (a[j] < a[i])
        d[i] = max(d[i], d[j] + 1);
    ans = max(ans, d[i]);
  }
  cout << ans << "\n";
  return 0;
}