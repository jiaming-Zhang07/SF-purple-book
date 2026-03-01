#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int val;
  int mins = 0, maxsum = (int)-2e9;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cin >> val;
    cur += val;
    maxsum = max(cur - mins, maxsum);
    mins = min(mins, cur);
  }
  printf("%d", maxsum);
  return 0;
}