#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int main() {
  while (cin >> s) {
    int n = s.size();
    int cnt0 = 0, cnt00 = 0;
    for (int i = 0; i < s.size(); i++)
      if (s[i] == '0') {
        cnt0++;
        if (s[(i + 1) % n] == '0')
          cnt00++;
      }
    int sh = cnt00 * n, ro = cnt0 * cnt0;
    if (sh == ro)
      cout << "EQUAL\n";
    else if (sh > ro)
      cout << "SHOOT\n";
    else
      cout << "ROTATE\n";
  }
  return 0;
}