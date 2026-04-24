#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    double a, b, s;
    cin >> a >> b >> s;
    if (s == 0) {
      cout << "100.000000%\n";
      continue;
    } else if (s >= a * b) {
      cout << "0.000000%\n";
      continue;
    }
    cout << fixed << setprecision(6) << 100 * (a * b - s - s * log(a * b / s)) / (a * b) << "%\n";
  }
  return 0;
}