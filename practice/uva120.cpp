#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  while (getline(cin, s)) {
    int n = 0, a[35];
    stringstream ss(s);
    while (ss >> a[n]) {
      n++;
      if (n > 1)
        cout << " ";
      cout << a[n - 1];
    }
    cout << endl;
    int a2[35];
    memcpy(a2, a, sizeof(a));
    sort(a2, a2 + n);
    for (int i = n - 1; i >= 0; i--) {
      int *t = find(a, a + n, a2[i]);
      if (t - a == i)
        continue;
      if (t - a > 0) {
        reverse(a, t + 1);
        cout << n - (t - a) << " ";
      }
      if (i) {
        reverse(a, a + i + 1);
        cout << n - i << " ";
      }
    }
    cout << 0 << endl;
  }
  return 0;
}