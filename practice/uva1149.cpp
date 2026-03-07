#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int l[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T, kase = 0;
  cin >> T;
  while (T--) {
    if (kase++)
      cout << endl;
    int n, L, ans = 0;
    cin >> n >> L;
    for (int i = 0; i < n; i++)
      cin >> l[i];
    sort(l, l + n);
    int lef = 0, r = n - 1;
    while (lef < r) {
      if (l[lef] + l[r] <= L)
        lef++;
      r--;
      ans++;
    }
    if (lef == r)
      ans++;
    cout << ans << endl;
  }
  return 0;
}