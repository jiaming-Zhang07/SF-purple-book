#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int cnt = 0;
    cin >> s;
    int n = strlen(s);
    int flag = 0;
    for (int i = 0; i < n; i++)
      if (flag == 0 && s[i] == 'l') {
        flag = 1;
      } else if (flag == 1 && s[i] == 'n')
        flag = 2;
      else if (flag == 2 && s[i] == 'c') {
        cnt++;
        flag = 0;
      }
    cout << cnt << "\n";
  }
}