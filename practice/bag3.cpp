#include <bits/stdc++.h>
using namespace std;
int f[1005];
int main() {
  int n, V, v, w;
  cin >> n >> V;
  for (int i = 1; i <= n; i++) {
    cin >> v >> w;
    for (int j = V; j >= v; j--) {
      f[j] = max(f[j], f[j - v] + w);
    }
  }
  cout << f[V] << "\n";
  return 0;
}