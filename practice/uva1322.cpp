#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 50005, INF = 1 << 30;
int tree[4 * maxn];
void build(int node, int l, int r) {
  if (l == r) {
    tree[node] = (l == 1) ? 0 : INF;
    return;
  }
  int mid = l + (r - l) / 2;
  build(node << 1, l, mid);
  build(node << 1 | 1, mid + 1, r);
  tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
}
int query(int node, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r)
    return tree[node];
  int mid = l + (r - l) / 2;
  int min_val = INF;
  if (ql <= mid)
    min_val = min(min_val, query(node << 1, l, mid, ql, qr));
  if (qr > mid)
    min_val = min(min_val, query(node << 1 | 1, mid + 1, r, ql, qr));
  return min_val;
}
void update(int node, int l, int r, int pos, int val) {
  if (l == r) {
    tree[node] = min(tree[node], val);
    return;
  }
  int mid = l + (r - l) / 2;
  if (pos <= mid)
    update(node << 1, l, mid, pos, val);
  else
    update(node << 1 | 1, mid + 1, r, pos, val);
  tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      int min_val = query(1, 1, n, u, v);
      if (min_val != INF)
        update(1, 1, n, v, min_val + 1);
    }
    cout << query(1, 1, n, n, n) << "\n";
    if (T)
      cout << "\n";
  }
  return 0;
}