#include <bits/stdc++.h>
using namespace std;
int ok[1005];
int main() {
  int n;
  while (scanf("%d", &n) == 1 && n) {
    vector<string> s(n);
    char ans[35] = {0};
    for (int i = 0; i < n; i++)
      cin >> s[i];
    sort(s.begin(), s.end());
    string s1 = s[n / 2 - 1], s2 = s[n / 2];
    for (int i = 0; i < (int)s1.size() && i < (int)s2.size(); i++) {
      if (s1[i] == s2[i] || i == (int)s1.size() - 1)
        ans[i] = s1[i];
      else {
        if (s2[i] - s1[i] == 1 && i == (int)s2.size() - 1) {
          ans[i] = s1[i];
          while (++i < (int)s1.size() - 1 && s1[i] == 'Z') {
            ans[i] = 'Z';
          }
          if (i == (int)s1.size() - 1)
            ans[i] = s1[i];
          else
            ans[i] = s1[i] + 1;
        } else
          ans[i] = s1[i] + 1;
        break;
      }
    }
    printf("%s\n", ans);
  }
  return 0;
}