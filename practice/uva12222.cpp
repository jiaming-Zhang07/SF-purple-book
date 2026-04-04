#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct car {
  int arr, t;
} L[205], R[205];
int d[205][205][2];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int l = 1, r = 1;
    memset(d, 0x3f, sizeof(d));
    while (n--) {
      char c;
      int arr, t;
      cin >> c >> arr >> t;
      if (c == 'A')
        L[l++] = {arr, t};
      else
        R[r++] = {arr, t};
    }
    d[0][0][0] = d[0][0][1] = 0;
    for (int i = 0; i < l; i++)
      for (int j = 0; j < r; j++) {
        if (i && d[i - 1][j][1] != 0x3f3f3f3f) {
          int s = max(d[i - 1][j][1], L[i].arr), enter = s;
          for (int k = i; k < l; k++) {
            if (k != i) {
              enter = max(enter + 10, L[k].arr);
              s = max(enter, s + L[k - 1].t + 10 - L[k].t);
            }
            d[k][j][0] = min(d[k][j][0], s + L[k].t);
          }
        }
        if (j && d[i][j - 1][0] != 0x3f3f3f3f) {
          int s = max(d[i][j - 1][0], R[j].arr), enter = s;
          for (int k = j; k < r; k++) {
            if (k != j) {
              enter = max(enter + 10, R[k].arr);
              s = max(enter, s + R[k - 1].t + 10 - R[k].t);
            }
            d[i][k][1] = min(d[i][k][1], s + R[k].t);
          }
        }
      }
    cout << min(d[l - 1][r - 1][0], d[l - 1][r - 1][1]) << "\n";
  }
  return 0;
}