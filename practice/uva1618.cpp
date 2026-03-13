#include <bits/stdc++.h>
using namespace std;
int n, a[5005], sorted_a[5005], N[5005], f[5005][5005], pre[5005], succ[5005];
// 检测模式 1: 存在 p < q < r < s 使得 N_r < N_p < N_s < N_q
bool weak() {
  fill(succ + 1, succ + n + 1, n + 1);
  for (int q = 1; q <= n; q++) {
    for (int r = q + 1; r <= n; r++)
      f[q][r] = succ[N[r]];
    int val = N[q];
    for (int i = val - 1; i > 0; i--)
      if (succ[i] > val)
        succ[i] = val;
      else
        break;
  }
  fill(pre + 1, pre + n + 1, 0);
  for (int r = n; r > 0; r--) {
    for (int q = 1; q < r; q++)
      if (N[q] > N[r] && f[q][r] < pre[N[q]])
        return true;
    int val = N[r];
    for (int i = val + 1; i <= n; i++)
      if (pre[i] < val)
        pre[i] = val;
      else
        break;
  }
  return false;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sorted_a[i] = a[i];
    }
    sort(sorted_a + 1, sorted_a + n + 1);
    for (int i = 1; i <= n; i++)
      N[i] = lower_bound(sorted_a + 1, sorted_a + 1 + n, a[i]) - sorted_a;
    if (weak()) {
      cout << "YES" << "\n";
      continue;
    }
    for (int i = 1; i <= n; i++)
      N[i] = n + 1 - N[i];
    if (weak())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}