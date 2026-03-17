#include <bits/stdc++.h>
using namespace std;
char s[100005];
int p[256];
int main() {
  p['x'] = 1;
  p['j'] = 2;
  p['t'] = 3;
  p['u'] = 4;
  int n;
  cin >> n;
  scanf("%s", s);
  int l = 0, r = 0, x;
  long long cnt = 0;
  int flag = 0;
  while (r < n) {
    if (!flag) {
      if (p[s[r]] == 1) {
        flag = 1;
        l = x = r;
      }
    } else {
      if (p[s[r]] - 1 > p[s[r - 1]])
        flag = 0;
      else if (p[s[r]] < p[s[r - 1]]) {
        if (p[s[r]] == 1) {
          flag = 1;
          l = x = r;
        } else
          flag = 0;
      } else if (p[s[r]] == 4)
        cnt += x - l + 1;
      else if (p[s[r]] == 1)
        x = r;
    }
    r++;
  }
  cout << cnt << "\n";
  return 0;
}