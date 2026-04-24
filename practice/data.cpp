#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> dist2(4, 10);
  uniform_int_distribution<int> dist(-10, 10);
  int n = dist2(rng);
  cout << n << "\n";
  for (int i = 0; i < n; i++)
    cout << dist(rng) << (i == n - 1 ? "\n" : " ");
  return 0;
}
// 7
// -2 -1 2 -9 10 -9 -1