#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[10], pow10[10];
int f(int n, int d) {
  string s = to_string(n);
  int ans = 0, len = s.size();
  for (int i = 1; i < len; i++) {
    ans += 9 * cnt[i - 1];
    if (d)
      ans += pow10[i - 1];
  }
  vector<int> pre(len);
  for (int i = 0; i < len; i++) {
    pre[i] = (s[i] - '0' == d);
    if (i)
      pre[i] += pre[i - 1];
  }
  for (int i = 0; i < len; i++) {
    int maxd = s[i] - '0' - 1;
    int st = 0;
    if (i == 0)
      st = 1;
    for (int j = st; j <= maxd; j++) {
      ans += cnt[len - i - 1];
      if (j == d)
        ans += pow10[len - i - 1];
      if (i)
        ans += pre[i - 1] * pow10[len - i - 1];
    }
  }
  return ans;
}
int main() {
  int a, b;
  pow10[0] = 1;
  for (int i = 1; i <= 8; i++)
    pow10[i] = pow10[i - 1] * 10;
  for (int i = 1; i <= 8; i++)
    cnt[i] = i * pow10[i - 1];
  while (cin >> a >> b && a) {
    if (b < a)
      swap(a, b);
    for (int i = 0; i < 10; i++) {
      if (i)
        cout << " ";
      cout << f(b + 1, i) - f(a, i);
    }
    cout << "\n";
  }
  return 0;
}