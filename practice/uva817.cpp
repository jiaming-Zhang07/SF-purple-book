#include <bits/stdc++.h>
using namespace std;
int n, a[100000], used[100000], maxcnt, len;
bool dfs(int cnt, int remlen, int pos) {
  if (cnt == maxcnt)
    return true;
  if (remlen == 0)
    return dfs(cnt + 1, len, 0);
  for (int i = pos; i < n; i++)
    if (!used[i] && a[i] <= remlen) {
      used[i] = 1;
      if (dfs(cnt, remlen - a[i], i + 1))
        return true;
      used[i] = 0;
      if (remlen == a[i] || remlen == len)
        return false;
      while (i < n - 1 && a[i] == a[i + 1])
        i++;
    }
  return false;
}
int main() {
  while (scanf("%d", &n) && n) {
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n, greater<int>());
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += a[i];
    for (len = a[0];; len++)
      if (sum % len == 0) {
        maxcnt = sum / len;
        if (dfs(0, len, 0)) {
          printf("%d\n", len);
          break;
        }
      }
  }
  return 0;
}