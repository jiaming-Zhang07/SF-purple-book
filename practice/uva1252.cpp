#include <bits/stdc++.h>
using namespace std;
int m, n;
const int INF = 1 << 30;
int a[130], d[1 << 11][1 << 11], num[1 << 11][1 << 11];
int dp(int s, int u) {
  if (num[s][u] <= 1)
    return 0;
  int &ans = d[s][u];
  if (ans > 0)
    return ans;
  else {
    ans = INF;
    for (int i = 0; i < m; i++)
      if (!((1 << i) & s)) {
        ans = min(ans, max(dp(s | (1 << i), u), dp(s | (1 << i), u | (1 << i))));
      }
    return ++ans;
  }
}
void init() {
  for (int s = 0; s < 1 << m; s++) {
    for (int s0 = s; s0; s0 = (s0 - 1) & s)
      d[s][s0] = num[s][s0] = 0;
    d[s][0] = num[s][0] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int s = 0; s < 1 << m; s++)
      num[s][s & a[i]]++;
  }
}
int main() {
  while (cin >> m >> n && m) {
    string s;
    for (int i = 0; i < n; i++) {
      cin >> s;
      a[i] = stoi(s, nullptr, 2);
    }
    init();
    cout << dp(0, 0) << "\n";
  }
  return 0;
}