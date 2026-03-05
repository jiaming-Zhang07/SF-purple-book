#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int A[maxn], pre[maxn], nex[maxn];
map<int, int> cur;
bool uniq(int i, int l, int r) {
  return pre[i] < l && nex[i] > r;
}
bool check(int l, int r) {
  if (l >= r)
    return true;
  for (int d = 0; l + d <= r - d; d++) {
    if (uniq(l + d, l, r))
      return check(l, l + d - 1) && check(l + d + 1, r);
    if (l + d == r + d)
      break;
    if (uniq(r - d, l, r))
      return check(l, r - d - 1) && check(r - d + 1, r);
  }
  return false;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cur.clear();
    for (int i = 0; i < n; i++) {
      cin >> A[i];
      if (cur.count(A[i]))
        pre[i] = cur[A[i]];
      else
        pre[i] = -1;
      cur[A[i]] = i;
    }
    cur.clear();
    for (int i = n - 1; i >= 0; i--) {
      if (cur.count(A[i]))
        nex[i] = cur[A[i]];
      else
        nex[i] = n;
      cur[A[i]] = i;
    }
    if (check(0, n - 1))
      printf("non-boring\n");
    else
      printf("boring\n");
  }
  return 0;
}