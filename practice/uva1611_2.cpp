#include <bits/stdc++.h>
using namespace std;
int a[10005], pos[10005], cnt;
pair<int, int> ans[50010];
void Swap(int L, int R) {
  ans[cnt++] = {L, R};
  int m = (R - L + 1) / 2;
  for (int i = L; i < m + L; i++) {
    swap(pos[a[i]], pos[a[m + i]]);
    swap(a[i], a[m + i]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    cnt = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
      if (pos[i] != i) {
        if (2 * pos[i] - i - 1 > n) {
          if (pos[i] - i + 1 & 1)
            Swap(i + 1, pos[i]);
          else
            Swap(i, pos[i]);
        }
        Swap(i, 2 * pos[i] - i - 1);
      }
    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++)
      cout << ans[i].first << " " << ans[i].second << "\n";
  }
  return 0;
}