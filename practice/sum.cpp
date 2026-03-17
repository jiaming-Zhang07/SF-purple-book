// 9:52
#include <bits/stdc++.h>
using namespace std;
int a[20005];
int main() {
  int n, m;
  cin >> n >> m;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    cout << a[i] << " ";
  }
  for (int i = 0; i < m; i++) {
    cout << sum % 10;
    a[n + i] = sum % 10;
    if (i != m - 1)
      cout << " ";
    sum = sum - a[i] + sum % 10;
  }
  cout << "\n";
}
// 10:02
