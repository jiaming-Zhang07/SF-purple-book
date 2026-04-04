#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int pow_mod(int a, int n, int m) {
  if (n == 0)
    return 1;
  int x = pow_mod(a, n / 2, m);
  int ans = x * x % m;
  if (n & 1)
    ans = (ans * a) % m;
  return ans;
}