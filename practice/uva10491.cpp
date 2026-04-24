#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  double a, b, c;
  while (cin >> a >> b >> c)
    cout << fixed << setprecision(5) << b / (a + b) * (b - 1) / (a + b - 1 - c) + a / (a + b) * b / (a + b - 1 - c) << "\n";
  return 0;
}