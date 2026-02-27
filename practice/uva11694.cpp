#include <bits/stdc++.h>
using namespace std;
int n, tar_deg[10][10], deg[10][10];
char ans[10][10];
int parent[100], rank[100];
bool unite(int u, int v) {
  int rootu = find(u), rootv = find(v);
}
void dfs(int r, int c) {
  int nextr = c == n ? r + 1 : r, nextc = c == n ? 0 : c + 1;
  int tl = r * (n + 1) + c, tr = r * (n + 1) + c + 1, bl = (r + 1) * (n + 1) + c, br = (r + 1) * (n + 1) + c + 1;
  if (unite(tl, br)) {
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
      for (int i = 0; i < n; i++)
        printf("%s\n", ans[i]);
    }
  }
  return 0;
}