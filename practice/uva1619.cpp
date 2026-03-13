#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
using ll = long long;
int a[maxn], L[maxn], R[maxn];
ll sum[maxn];
int main() {
  int n, kase = 0;
  while (cin >> n) {
    if (kase++)
      cout << "\n";
    int ansl = 1, ansr = 1;
    stack<int> s, s2;
    ll cur, ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i];
      while (!s.empty() && a[s.top()] >= a[i])
        s.pop();
      L[i] = s.empty() ? 1 : s.top() + 1;
      s.push(i);
    }
    for (int i = n; i > 0; i--) {
      while (!s2.empty() && a[s2.top()] >= a[i])
        s2.pop();
      R[i] = s2.empty() ? n : s2.top() - 1;
      s2.push(i);
    }
    for (int i = 1; i <= n; i++) {
      cur = (sum[R[i]] - sum[L[i] - 1]) * a[i];
      if (cur > ans) {
        ansl = L[i];
        ansr = R[i];
        ans = cur;
      } else if (cur == ans && (ansr - ansl > R[i] - L[i] || (ansr - ansl == R[i] - L[i] && ansr > R[i]))) {
        ansl = L[i];
        ansr = R[i];
      }
    }
    cout << ans << "\n" << ansl << " " << ansr << "\n";
  }
  return 0;
}