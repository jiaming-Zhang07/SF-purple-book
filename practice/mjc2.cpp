#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ans = 0;
  int n;
  cin >> n;
  long long val;
  cin >> val;
  for (int i = 0; i < n - 1; i++) {
    cin >> val;
    if (val > 0)
      ans += val;
  }
  return 0;
}