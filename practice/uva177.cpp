#include <bits/stdc++.h>
using namespace std;
char g[400][400];
int dr[][2] = {{-1, 0}, {0, 0}, {-1, 0}, {1, 1}};
int dc[][2] = {{1, 1}, {1, -1}, {-1, -1}, {1, -1}};
int main() {
  int n;
  while (cin >> n && n) {
    memset(g, 0, sizeof(g));
    vector<int> dir;
    dir.push_back(0);
    for (int i = 0; i < n; i++) {
      for (int j = (int)dir.size() - 1; j >= 0; j--) {
        dir.push_back((dir[j] + 1) % 4);
      }
    }
    int r = 200, c = 200;
    g[r][c] = '_';
    int maxr = r, minr = r, maxc = c, minc = c;
    for (int i = 1; i < dir.size(); i++) {
      int k = 1;
      if (dir[i - 1] < 2)
        k = 0;
      r += dr[dir[i]][k];
      c += dc[dir[i]][k];
      if (r > maxr)
        maxr = r;
      if (r < minr)
        minr = r;
      if (c > maxc)
        maxc = c;
      if (c < minc)
        minc = c;
      if (dir[i] % 2)
        g[r][c] = '|';
      else
        g[r][c] = '_';
    }
    for (int i = minr; i <= maxr; i++) {
      int last;
      for (last = maxc;; last--)
        if (g[i][last] != '\0')
          break;
      for (int j = minc; j <= last; j++)
        if (g[i][j] == '\0') {
          printf(" ");
        } else {
          printf("%c", g[i][j]);
        }
      printf("\n");
    }
    printf("^\n");
  }
  return 0;
}