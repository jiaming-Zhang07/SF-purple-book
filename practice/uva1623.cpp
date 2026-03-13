#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int m, n, last[maxn], ans[maxn];
bool solve() {
  int val;
  set<int> date;
  bool ok = true;
  for (int i = 0; i < m; i++) {
    scanf("%d", &val);
    if (ok) {
      if (val > 0) {
        auto it = date.lower_bound(last[val]);
        if (it == date.end())
          ok = false;
        else {
          ans[*it] = val;
          date.erase(it);
          last[val] = i;
        }
      } else
        date.insert(i);
    }
  }
  for (int x : date) {
    ans[x] = 0;
  }
  return ok;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      last[i] = 0;
    for (int i = 0; i < m; i++)
      ans[i] = -1;
    if (solve()) {
      printf("YES\n");
      int k = 0;
      for (int i = 0; i < m; i++)
        if (ans[i] != -1) {
          if (k++)
            printf(" ");
          printf("%d", ans[i]);
        }
      printf("\n");
    } else
      printf("NO\n");
  }
  return 0;
}