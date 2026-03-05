#include <bits/stdc++.h>
using namespace std;
int A[1000005], last[1000005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    map<int, int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
      if (!s.count(A[i]))
        last[i] = -1;
      else
        last[i] = s[A[i]];
      s[A[i]] = i;
    }
    int L = 0, R = 0, ans = 0;
    while (R < n) {
      while (R < n && last[R] < L)
        R++;
      ans = max(ans, R - L);
      L++;
    }
    printf("%d\n", ans);
  }
  return 0;
}