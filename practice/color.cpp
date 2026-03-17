#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
int adj[maxn];
bool no_edges_inside[1 << maxn];
int d[1 << maxn];
int main() {
  int n, m;
  cin >> n >> m;
  int v1, v2;
  for (int i = 0; i < m; i++) {
    cin >> v1 >> v2;
    adj[v1] |= 1 << v2;
    adj[v2] |= 1 << v1;
  }
  no_edges_inside[0] = true;
  for (int s = 1; s < 1 << n; s++) {
    no_edges_inside[s] = true;
    for (int i = 0; i < n; i++)
      if ((s & 1 << i) && (s & adj[i])) {
        no_edges_inside[s] = false;
        break;
      }
  }
  for (int s = 1; s < 1 << n; s++) {
    d[s] = 100;
    for (int s0 = s; s0; s0 = (s0 - 1) & s)
      if (no_edges_inside[s0]) {
        d[s] = min(d[s], d[s ^ s0] + 1);
      }
  }
  return 0;
}