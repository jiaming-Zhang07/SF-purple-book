#include <bits/stdc++.h>
using namespace std;
using ll = long long;
char s[10005];
int main() {
  ll m, ans = 0;
  cin >> s >> m;
  int n = strlen(s);
  for (int i = 0; i < n; i++)
    ans = (ans * 10 + s[i] - '0') % m;
  cout << ans << "\n";
  return 0;
}