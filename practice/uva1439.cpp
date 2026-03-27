#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 105, maxr = 15;
int u[maxn], v[maxn];
int G[maxr][maxr];
bool ind[1 << maxr];
int best[1 << maxr], cen[maxr], d[1 << maxr];
bool inde(int s) {
  for (int i = 0; i < maxr; i++)
    if (s & 1 << i)
      for (int j = 0; j < maxr; j++)
        if (j != i && (s & 1 << j) && G[i][j] == 1)
          return false;
  return true;
}
int countset(int S) {
  if (S == 0)
    return 0;
  int &ans = d[S];
  if (ans > 0)
    return ans;
  ans = 1 << 30;
  for (int s = S; s; s = S & (s - 1))
    if (ind[s]) {
      int nans = countset(S ^ s) + 1;
      if (ans > nans) {
        ans = nans;
        best[S] = s;
      }
    }
  return ans;
}
int main() {
  int m;
  while (cin >> m) {
    memset(d, 0, sizeof(d));
    memset(G, 0, sizeof(G));
    memset(ind, 0, sizeof(ind));
    int use = 0;
    for (int i = 0; i < m; i++) {
      char c;
      cin >> c;
      u[i] = c - 'L';
      cin >> c;
      v[i] = c - 'L';
      use |= 1 << u[i];
      use |= 1 << v[i];
      G[u[i]][v[i]] = 1;
    }
    for (int s = use; s; s = (s - 1) & use) {
      if (inde(s))
        ind[s] = true;
      else
        ind[s] = false;
    }
    int cnt = countset(use);
    cout << cnt - 2 << "\n";
    int k = 0;
    int s = use;
    while (s) {
      int bs = best[s];
      for (int i = 0; i < maxr; i++)
        if (bs & 1 << i) {
          cen[i] = k;
        }
      k++;
      s ^= bs;
    }
    for (int i = 0; i < m; i++) {
      if (cen[u[i]] < cen[v[i]])
        swap(u[i], v[i]);
      printf("%c %c\n", u[i] + 'L', v[i] + 'L');
    }
  }
  return 0;
}