#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int main() {
  cin >> s;
  int n = strlen(s);
  int cnt = 0;
  for (int i = 0; i < n - i - 1; i++)
    if (s[i] != s[n - i - 1])
      cnt++;
  cout << cnt << "\n";
  return 0;
}