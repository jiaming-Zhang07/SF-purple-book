#include <bits/stdc++.h>
using namespace std;
int maxd, wall[10][15];
char ans[10000];
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
char dir[] = {'S', 'N', 'E', 'W'};
bool dfs(int r0, int c0, int r, int c, int d) {
  if (r < 0 || c < 0 || r > 3 || c > 5) {
    ans[d] = '\0';
    return true;
  }
  if (d == maxd)
    return false;
  int cr = 2 * r + 1, cc = 2 * c + 1;
  for (int i = 0; i < 4; i++) {
    if (r + dr[i] == r0 && c + dc[i] == c0)
      continue;
    int nr = r + dr[i], nc = c + dc[i], wr = cr + dr[i], wc = cc + dc[i], nwr = cr + 3 * dr[i], nwc = cc + 3 * dc[i];
    if (!wall[wr][wc]) {
      ans[d] = dir[i];
      if (dfs(r, c, nr, nc, d + 1))
        return true;
    } else if (nr >= 0 && nr <= 3 && nc >= 0 && nc <= 5 && !wall[nwr][nwc]) {
      wall[wr][wc] = 0;
      wall[nwr][nwc] = 1;
      ans[d] = dir[i];
      if (dfs(r, c, nr, nc, d + 1))
        return true;
      wall[wr][wc] = 1;
      wall[nwr][nwc] = 0;
    }
  }
  return false;
}
int main() {
  int r, c;
  while (scanf("%d%d", &c, &r) == 2 && r) {
    memset(wall, 0, sizeof(wall));
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 6; j++) {
        int w;
        scanf("%d", &w);
        if (w & 1) // w
          wall[2 * i + 1][2 * j] = 1;
        if (w & 2) // n
          wall[2 * i][2 * j + 1] = 1;
        if (w & 4) // e
          wall[2 * i + 1][2 * (j + 1)] = 1;
        if (w & 8) // s
          wall[2 * (i + 1)][2 * j + 1] = 1;
      }
    for (maxd = 1;; maxd++)
      if (dfs(-2, -2, r - 1, c - 1, 0))
        break;
    printf("%s\n", ans);
  }
  return 0;
}