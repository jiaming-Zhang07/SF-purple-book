#include <bits/stdc++.h>
using namespace std;
int main() {
  int val;
  int n;
  cin >> n;
  cin >> val;
  int maxc = val, maxs = val;
  for (int i = 1; i < n; i++) {
    cin >> val;
    maxc = max(val, maxc + val);
    maxs = max(maxc, maxs);
  }
  printf("%d", maxs);
  return 0;
}