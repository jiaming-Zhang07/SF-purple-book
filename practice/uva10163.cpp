#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int L;
int n, m;
const int INF = 1 << 30;
int p[35], d[105];
int main() {
  while (cin >> n >> m && n) {
    for (int i = 0; i < m; i++)
      cin >> p[i];
    int l = 0, r = 1005;
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      int sum = 0;
      for (int i = 0; i < m; i++)
        sum += p[i] / mid;
      if (sum < n)
        r = mid - 1;
      else
        l = mid;
    }
    L = l;
    if (L == 0) {
      cout << "0 0\n";
      continue;
    }
    fill(d, d + n + 1, INF);
    d[0] = 0;
    for (int i = 0; i < m; i++)
      for (int j = n; j > 0; j--)
        d[j] = min(d[j], d[max(0, j - p[i] / L)] + p[i]);
    cout << L << " " << d[n] << "\n";
  }
  return 0;
}