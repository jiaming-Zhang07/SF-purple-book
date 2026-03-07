#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int x[3 * maxn], ok[2 * maxn], cnt[maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, s;
    cin >> s >> n;
    fill(x, x + n + 2 * s, -1);
    fill(ok, ok + n + s + 1, 0);
    fill(cnt + 1, cnt + s + 1, 0);
    for (int i = 0; i < n; i++)
      cin >> x[s + i];
    int tot = 0;
    for (int i = 0; i < n + s + 1; i++) {
      if (tot == s)
        ok[i] = 1;
      if (i < s && tot == i)
        ok[i] = 1;
      if (i >= n && tot == n + s - i)
        ok[i] = 1;
      if (i > n && i < s && tot == n)
        ok[i] = 1;
      if (i == n + s)
        break;
      if (x[i] != -1 && --cnt[x[i]] == 0)
        tot--;
      if (x[i + s] != -1 && cnt[x[i + s]]++ == 0)
        tot++;
    }
    int ans = 0;
    for (int i = 0; i < s; i++) {
      int valid = 1;
      for (int j = i; j < n + s + 1; j += s)
        if (!ok[j])
          valid = 0;
      if (valid)
        ans++;
    }
    cout << ans << endl;
  }
  return 0;
}