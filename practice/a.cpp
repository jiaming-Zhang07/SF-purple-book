#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 850000;
int sum[M * 30], son[M * 30][2], n, d, w, a[60];
ll ans;
vector<pair<int, int>> r[2];
void ldfs(int pos, int last, int en, int sum) {
  if (pos > en) {
    if (last == 0)
      return;
    if (sum <= w)
      ans++;
    r[0].push_back({last, sum});
    return;
  }
  ldfs(pos + 1, last, en, sum);
  ldfs(pos + d, pos, en, sum ^ a[pos]);
}
void rdfs(int pos, int first, int en, int sum) {
  if (pos > en) {
    if (first == 0)
      return;
    if (sum <= w)
      ans++;
    r[1].push_back({first, sum});
    return;
  }
  rdfs(pos + 1, first, en, sum);
  if (first == 0)
    first = pos;
  rdfs(pos + d, first, en, sum ^ a[pos]);
}
int tot;
void insert(int val) {
  int u = 0;
  for (int j = 29; j >= 0; j--) {
    int c = val >> j & 1;
    if (!son[u][c])
      son[u][c] = ++tot;
    u = son[u][c];
    sum[u]++;
  }
}
void query(int val) {
  int u = 0;
  for (int j = 29; j >= 0; j--) {
    int c1 = val >> j & 1, c2 = w >> j & 1;
    if (c2 == 0)
      u = son[u][c1];
    else {
      ans += sum[son[u][c1]];
      u = son[u][c1 ^ 1];
    }
    if (u == 0)
      break;
  }
  if (u)
    ans += sum[u];
}
int main() {
  cin >> n >> d >> w;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  if (n == 1) {
    cout << (a[1] <= w ? 1 : 0) << "\n";
    return 0;
  }
  int mid = n / 2;
  ldfs(1, 0, mid, 0);
  rdfs(mid + 1, 0, n, 0);
  sort(r[0].begin(), r[0].end());
  sort(r[1].begin(), r[1].end());
  for (int i = 0, j = 0; i < r[1].size(); i++) {
    while (j < r[0].size() && r[0][j].first + d <= r[1][i].first) {
      insert(r[0][j].second);
      j++;
    }
    query(r[1][i].second);
  }
  cout << ans << "\n";
  return 0;
}