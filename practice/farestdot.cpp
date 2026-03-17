#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
vector<int> G[maxn];
int n, maxd, des;
int dista[maxn], distb[maxn];
void dfs(int *dist, int idx, int last, int d) {
  dist[idx] = d;
  if (d > maxd) {
    maxd = d;
    des = idx;
  }
  for (int x : G[idx])
    if (x != last)
      dfs(dist, x, idx, d + 1);
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a1, a2;
    cin >> a1 >> a2;
    G[a1].push_back(a2);
    G[a2].push_back(a1);
  }
  dfs(dista, 1, 0, 0);
  int a = des;
  maxd = 0;
  dfs(dista, a, 0, 0);
  int b = des;
  dfs(distb, b, 0, 0);
  int id;
  cin >> id;
  cout << max(dista[id], distb[id]);
  return 0;
}