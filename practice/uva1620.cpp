#include <bits/stdc++.h>
using namespace std;
int a[505];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    if ((n & 1) == 0) {
      cout << "possible\n";
      continue;
    }
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++) {
        if (a[j] < a[i])
          cnt++;
      }
    if (cnt & 1)
      cout << "impossible\n";
    else
      cout << "possible\n";
  }
  return 0;
}