#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int p[maxn];
int main() {
  int T, kase = 0;
  cin >> T;
  while (T--) {
    printf("Case %d: ", ++kase);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    int sum = 0, val, mins = 0, ans = 1;
    for (int i = 0; i < n; i++) {
      cin >> val;
      sum += p[i] - val;
      if (sum < mins) {
        ans = i + 2;
        mins = sum;
      }
    }
    if (sum >= 0)
      printf("Possible from station %d\n", ans);
    else
      printf("Not possible\n");
  }
  return 0;
}