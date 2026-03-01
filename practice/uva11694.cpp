#include <bits/stdc++.h>
using namespace std;
struct change {
  int u, v;
  bool addrank;
};
int n, tar_deg[10][10], deg[10][10];
char ans[10][10];
int parent[100], ran[100];
vector<change> history;
int find(int u) {
  while (parent[u] != u)
    u = parent[u];
  return u;
}
bool unite(int u, int v) {
  int rootu = find(u), rootv = find(v);
  if (rootu == rootv)
    return false;
  if (ran[rootu] < ran[rootv])
    swap(rootu, rootv);
  history.push_back({rootu, rootv, ran[rootu] == ran[rootv]});
  parent[rootv] = rootu;
  if (ran[rootu] == ran[rootv])
    ran[rootu]++;
  return true;
}
void traceback() {
  change t = history.back();
  history.pop_back();
  if (t.addrank)
    ran[t.u]--;
  parent[t.v] = t.v;
}
bool check(int r, int c) {
  if (tar_deg[r][c] == -1)
    return true;
  return deg[r][c] == tar_deg[r][c];
}
void dfs(int r, int c) {
  if (r == n)
    throw 1;
  int nextr = c == n - 1 ? r + 1 : r, nextc = c == n - 1 ? 0 : c + 1;
  int tl = r * (n + 1) + c, tr = r * (n + 1) + c + 1, bl = (r + 1) * (n + 1) + c, br = (r + 1) * (n + 1) + c + 1;
  if (unite(tl, br)) {
    ans[r][c] = '\\';
    deg[r][c]++;
    deg[r + 1][c + 1]++;
    bool ok = true;
    if (!check(r, c))
      ok = false;
    if (c == n - 1 && r == n - 1 && (!check(r, c + 1) || !check(r + 1, c + 1) || !check(r + 1, c)))
      ok = false;
    else if (c == n - 1 && !check(r, c + 1))
      ok = false;
    else if (r == n - 1 && !check(r + 1, c))
      ok = false;
    if (ok)
      dfs(nextr, nextc);
    deg[r][c]--;
    deg[r + 1][c + 1]--;
    traceback();
  }
  if (unite(bl, tr)) {
    ans[r][c] = '/';
    deg[r + 1][c]++;
    deg[r][c + 1]++;
    bool ok = true;
    if (!check(r, c))
      ok = false;
    if (c == n - 1 && r == n - 1 && (!check(r, c + 1) || !check(r + 1, c + 1) || !check(r + 1, c)))
      ok = false;
    else if (c == n - 1 && !check(r, c + 1))
      ok = false;
    else if (r == n - 1 && !check(r + 1, c))
      ok = false;
    if (ok)
      dfs(nextr, nextc);
    deg[r + 1][c]--;
    deg[r][c + 1]--;
    traceback();
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(deg, 0, sizeof(deg));
    cin >> n;
    for (int i = 0; i < n + 1; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < n + 1; j++) {
        if (s[j] == '.')
          tar_deg[i][j] = -1;
        else
          tar_deg[i][j] = s[j] - '0';
        parent[i * (n + 1) + j] = i * (n + 1) + j;
      }
    }
    try {
      dfs(0, 0);
    } catch (int e) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
          printf("%c", ans[i][j]);
        printf("\n");
      }
    }
  }
  return 0;
}