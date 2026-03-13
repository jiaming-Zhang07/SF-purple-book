#include <bits/stdc++.h>
using namespace std;
int n, W;
int w[1005], v[1005], d[10005];
int main() {
  cin >> n >> W;
  for (int i = 0; i < n; i++)
    cin >> w[i] >> v[i];
  for (int i = 0; i < n; i++)
    for (int j = w[i]; j <= W; j++)
      d[j] = max(d[j], d[j - w[i]] + v[i]);
  cout << d[W] << "\n";
  return 0;
}