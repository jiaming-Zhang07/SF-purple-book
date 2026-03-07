#include <bits/stdc++.h>
using namespace std;
char s[105], t[105];
int main() {
  int T, kase = 0;
  scanf("%d", &T);
  while (T--) {
    int diff[2] = {0}, ques[2] = {0}, ans = 0;
    bool ok = false;
    scanf("%s%s", s, t);
    for (int i = 0; s[i] != '\0'; i++) {
      if (s[i] == '?')
        ques[t[i] - '0']++;
      else if (s[i] != t[i])
        diff[s[i] - '0']++;
    }
    ans += ques[0] + ques[1];
    int need;
    if (diff[0] >= diff[1])
      need = 0;
    else
      need = 1;
    ans += diff[need ^ 1];
    int cnt = diff[need] - diff[need ^ 1];
    if (need == 0 || cnt <= ques[need]) {
      ok = true;
      ans += cnt;
    }
    if (!ok)
      ans = -1;
    printf("Case %d: %d\n", ++kase, ans);
  }
  return 0;
}