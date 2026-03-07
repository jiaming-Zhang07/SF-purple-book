#include <bits/stdc++.h>
using namespace std;
char s[100005], ans[100005];
int main() {
  int n, d;
  while (scanf("%d%d", &n, &d) == 2 && n) {
    scanf("%s", s);
    int m = n - d;
    int D = 0;
    for (int i = 0; i < n; i++) {
      while (d > 0 && D > 0 && s[i] > ans[D - 1]) {
        D--;
        d--;
      }
      ans[D++] = s[i];
    }
    ans[m] = '\0';
    printf("%s\n", ans);
  }
  return 0;
}