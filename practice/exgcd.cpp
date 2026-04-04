#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void exgcd(int a, int b, int &d, int &x, int &y) {
  if (b == 0) {
    x = 1;
    d = a;
    y = 0;
    return;
  }
  exgcd(b, a % b, d, y, x);
  y -= a / b * x;
}
int main() {
  return 0;
}