#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n, m;
struct gate {
  int a, b, o;
} g[maxn];
int output(int k) {
  for (int i = 1; i <= m; i++) {
    int a = g[i].a > 0 ? g[g[i].a].o : -g[i].a <= k;
    int b = g[i].b > 0 ? g[g[i].b].o : -g[i].b <= k;
    g[i].o = !(a && b);
  }
  return g[m].o;
}
int solve(int v0) {
  int l = 1, r = n;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (output(m) == v0)
      l = m + 1;
    else
      r = m;
  }
  return l;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
      scanf("%d%d", &g[i].a, &g[i].b);
    int v0 = output(0);
    int vn = output(n);
    if (v0 == vn) {
      for (int i = 0; i < n; i++)
        printf("0");
      printf("\n");
    } else {
      int t = solve(v0);
      for (int i = 1; i < t; i++)
        printf("1");
      printf("x");
      for (int i = t + 1; i <= n; i++)
        printf("0");
      printf("\n");
    }
  }
  return 0;
}