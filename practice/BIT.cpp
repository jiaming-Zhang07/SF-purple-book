#include <bits/stdc++.h>
using namespace std;
int a[3005], b[3005];
int m;
int tree[3005];
int lowbit(int r) {
  return r & -r;
}
int query(int r) {
  int res = 0;
  for (; r > 0; r -= lowbit(r)) {
    res += tree[r];
  }
  return res;
}
void update(int r, int val) {
  for (; r <= m; r += lowbit(r)) {
    tree[r] += val;
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  memcpy(b, a, sizeof(a));
  sort(b, b + n);
  m = unique(b, b + n) - b;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int rank = lower_bound(b, b + m, a[i]) - b + 1;
    ans += query(rank - 1);
    update(rank, 1);
  }
  cout << ans << "\n";
  return 0;
}