#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n && n) {
    long long sumwork = 0, val, sum = 0;
    for (int i = 0; i < n - 1; i++) {
      cin >> val;
      sum += val;
      sumwork += abs(sum);
    }
    cin >> val;
    printf("%lld\n", sumwork);
  }
  return 0;
}