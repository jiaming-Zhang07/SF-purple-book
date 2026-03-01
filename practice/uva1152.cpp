#include <bits/stdc++.h>
using namespace std;
int a[4][4005], sum[4005 * 4005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 4; j++)
        cin >> a[j][i];
    }
    int c = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        sum[c++] = a[0][i] + a[1][j];
      }
    sort(sum, sum + c);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        cnt += upper_bound(sum, sum + c, -a[2][i] - a[3][j]) - lower_bound(sum, sum + c, -a[2][i] - a[3][j]);
      }
    printf("%lld\n", cnt);
    if (T)
      printf("\n");
  }
  return 0;
}