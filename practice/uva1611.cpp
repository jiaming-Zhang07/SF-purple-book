#include <bits/stdc++.h>
using namespace std;
int a[10005], pos[10005], cnt;
pair<int, int> ans[50010];
void Swap(int a1, int a2) {
  swap(a[a1], a[a2]);
  swap(pos[a[a1]], pos[a[a2]]);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
      if (pos[i] != i - 1) {
        if (2 * pos[i] - i >= n) {
          if (pos[i] - i + 2 != 1 && (pos[i] - i + 2) & 1) {
            ans[cnt++] = {pos[i], pos[i] + 1};
            Swap(pos[i] - 1, pos[i]);
          }
          ans[cnt++] = {i, pos[i] + 1};
          int d = (pos[i] - i + 2) / 2;
          for (int j = 0; j < d; j++) {
            Swap(i - 1 + j, i - 1 + d + j);
          }
        }
        if (pos[i] != i - 1) {
          ans[cnt++] = {i, 2 * pos[i] - i + 1};
          int st = pos[i];
          for (int j = 0; j < st - i + 1; j++) {
            Swap(i - 1 + j, st + j);
          }
        }
      }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
      printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}