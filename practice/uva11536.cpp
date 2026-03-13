#include <bits/stdc++.h>
using namespace std;
int a[1000005] = {1, 2, 3}, cnt[1005];
int main() {
  int T, kase = 0;
  cin >> T;
  while (T--) {
    printf("Case %d: ", ++kase);
    int n, m, k;
    cin >> n >> m >> k;
    int ans = n + 1, tot = 0;
    for (int i = 3; i < n; i++)
      a[i] = (a[i - 3] + a[i - 2] + a[i - 1]) % m + 1;
    int l = 0, r = 0, val;
    memset(cnt, 0, sizeof(cnt));
    while (r < n) {
      val = a[r];
      cnt[val]++;
      if (val <= k && cnt[val] == 1)
        tot++;
      while (a[l] > k || cnt[a[l]] > 1) {
        cnt[a[l]]--;
        l++;
      }
      r++;
      if (tot == k)
        ans = min(ans, r - l);
    }
    if (ans == n + 1)
      printf("sequence nai\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}