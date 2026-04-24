#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int h, w;
  while (cin >> h >> w) {
    string s;
    int ans = 0;
    for (int i = 0; i < h; i++) {
      cin >> s;
      bool flag = false;
      for (int j = 0; j < s.size(); j++)
        if (s[j] != '.') {
          if (!flag) {
            ans += 1;
            flag = true;
          } else {
            flag = false;
          }
        } else if (flag)
          ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}