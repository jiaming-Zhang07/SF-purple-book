#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
char s[maxn][maxn];
int height[maxn], ans[maxn * 2];
struct rect {
  int c, h;
} r[maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    memset(height, 0, sizeof(height));
    memset(ans, 0, sizeof(ans));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      scanf("%s", s[i]);
    for (int i = 0; i < n; i++) {
      int top = -1;
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '#') {
          height[j] = 0;
          top = -1;
        } else {
          height[j]++;
          rect t = {j, height[j]};
          if (top == -1)
            r[++top] = t;
          else {
            while (top >= 0 && r[top].h > t.h) {
              t.c = r[top--].c;
            }
            if (top < 0 || r[top].h - r[top].c < t.h - t.c)
              r[++top] = t;
          }
          ans[r[top].h + j - r[top].c + 1]++;
        }
      }
    }
    for (int i = 2; i <= n + m; i++)
      if (ans[i])
        printf("%d x %d\n", ans[i], i * 2);
  }
  return 0;
}