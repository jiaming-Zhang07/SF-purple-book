#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  double k, l, s, w;
  while (cin >> k >> l >> s >> w && abs(k) > 1e-9) {
    if ((2 * 9.81 * w + sqrt(4 * 9.81 * 9.81 * w * w + 4 * k * 2 * 9.81 * w * l)) / 2 / k < s - l) {
      cout << "Stuck in the air.\n";
      continue;
    }
    if (9.81 * w * s - k * (s - l) * (s - l) / 2 > 50 * w) {
      cout << "Killed by the impact.\n";
      continue;
    }
    cout << "James Bond survives.\n";
  }
  return 0;
}