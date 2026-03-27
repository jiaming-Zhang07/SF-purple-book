#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s, d[105][105];
string solve(int st, int en) {
  string &ans = d[st][en], t;
  if (ans != "")
    return ans;
  ans = s.substr(st, en - st);
  for (int len = 1; len <= (en - st) / 2; len++)
    if ((en - st) % len == 0) {
      bool ok = true;
      for (int i = len; i < en - st; i++) {
        if (s[st + i] != s[st + i % len]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        t = to_string((en - st) / len) + "(" + solve(st, st + len) + ")";
        if (ans.size() > t.size())
          ans = t;
      }
    }
  for (int k = 1; k < en - st; k++) {
    t = solve(st, st + k) + solve(st + k, en);
    if (ans.size() > t.size())
      ans = t;
  }
  return ans;
}
int main() {
  while (cin >> s) {
    for (int i = 0; i < s.size() + 1; i++)
      for (int j = 0; j < s.size() + 1; j++)
        d[i][j].clear();
    cout << solve(0, s.size()) << "\n";
  }
  return 0;
}