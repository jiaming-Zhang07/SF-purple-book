#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
char s[maxn];
int p[maxn], sum[maxn];
int cmp(int x1, int x2, int x3, int x4) {
  return (sum[x2] - sum[x1 - 1]) * (x4 - x3 + 1) - (sum[x4] - sum[x3 - 1]) * (x2 - x1 + 1);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, l;
    scanf("%d%d%s", &n, &l, s + 1);
    int ansl = 1, ansr = l;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + s[i] - '0';
    int i = 0, j = 0;
    for (int t = l; t <= n; t++) {
      while (j - i > 1 && cmp(p[j - 1], t - l, p[j - 2], t - l) <= 0)
        j--;
      p[j++] = t - l + 1;
      while (j - i > 1 && cmp(p[i], t, p[i + 1], t) <= 0)
        i++;
      int c = cmp(p[i], t, ansl, ansr);
      if (c > 0 || (c == 0 && t - p[i] < ansr - ansl)) {
        ansl = p[i];
        ansr = t;
      }
    }
    printf("%d %d\n", ansl, ansr);
  }
  return 0;
}