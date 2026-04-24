#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 50005;
int phi[maxn];
int main() {
  phi[1] = 1;
  for (int i = 2; i <= maxn; i++)
    if (!phi[i])
      for (int j = i; j <= maxn; j += i) {
        if (!phi[j])
          phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
  int n;
  while (cin >> n && n) {
    int sum = 1;
    for (int i = 2; i <= n; i++)
      sum += phi[i] * 2;
    cout << sum << "\n";
  }
  return 0;
}