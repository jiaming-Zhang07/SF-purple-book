#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> s;
    int ans = 0;
    int n = strlen(s);
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(' && r == 0)
        l++;
      else if (s[i] == '(' && r != 0) {
        ans += r;
        r--;
      } else if (s[i] == ')' && l == 0)
        r++;
      else
        l--;
    }
    cout << ans << "\n";
  }
  return 0;
}