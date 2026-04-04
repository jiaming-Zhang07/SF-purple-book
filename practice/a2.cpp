// 操作次数多但后面值都不变了
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;
int a[maxn];
int main() {
  int n, q;
  cin >> n >> q;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int s = 0;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    if (sum == 0) {
      cout << 0 << "\n";
      continue;
    }
    if (x == 1)
      cout << sum << "\n";
    else {
      sum = 0;
      for (int i = s; i < n; i++) {
        a[i] /= x;
        sum += a[i];
        if (a[i] == 0) {
          swap(a[i], a[s]);
          s++;
        }
      }
      cout << sum << "\n";
    }
  }
  return 0;
}