#include <bits/stdc++.h>
using namespace std;
int A[1000005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> A[i];
    int L = 0, R = 0, ans = 0;
    set<int> s;
    while (R < n) {
      while (R < n && !s.count(A[R]))
        s.insert(A[R++]);
      ans = max(ans, R - L);
      s.erase(A[L]);
      L++;
    }
    printf("%d\n", ans);
  }
  return 0;
}