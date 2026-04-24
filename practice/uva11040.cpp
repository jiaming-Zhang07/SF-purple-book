#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[9][9];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int t;
    for (int i = 0; i < 6; i++)
      cin >> t;
    vector<int> b(4);
    for (int i = 0; i < 4; i++)
      cin >> b[i];
    for (int i = 0; i < 5; i++) {
      cin >> a[8][2 * i];
    }
    for (int i = 0; i < 4; i++)
      a[8][2 * i + 1] = (b[i] - a[8][2 * i] - a[8][2 * i + 2]) / 2;
    for (int i = 7; i >= 0; i--)
      for (int j = 0; j < i + 1; j++)
        a[i][j] = a[i + 1][j] + a[i + 1][j + 1];
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < i + 1; j++)
        cout << a[i][j] << (j == i ? "\n" : " ");
  }
  return 0;
}