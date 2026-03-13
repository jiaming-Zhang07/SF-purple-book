#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      cin >> a[i][j];
  for (int i = n - 1; i > 0; i--)
    for (int j = 1; j <= i; j++)
      a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
  cout << a[1][1] << "\n";
  return 0;
}