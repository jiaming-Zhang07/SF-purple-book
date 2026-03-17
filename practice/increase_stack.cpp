#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[10005];
int main() {
  int n;
  ll ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  a[0] = -1;
  a[n + 1] = 0;
  stack<int> s;
  for (int i = 0; i <= n + 1; i++) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      ll h = a[s.top()];
      s.pop();
      ll w = i - s.top() - 1;
      ans = max(ans, h * w);
    }
    s.push(i);
  }
  cout << ans << "\n";
  return 0;
}