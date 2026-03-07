#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int p[maxn], s[maxn], h[maxn];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> p[i];
    for (int i = 0; i < n; i++)
      cin >> s[i];
    int level = s[0];
    for (int i = 0; i < n; i++) {
      if (level > s[i])
        level = s[i];
      else if (level < p[i])
        level = p[i];
      h[i] = level;
    }
    level = s[n - 1];
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (level > s[i])
        level = s[i];
      else if (level < p[i])
        level = p[i];
      ans += min(level, h[i]) - p[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}