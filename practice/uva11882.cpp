#include <bits/stdc++.h>
using namespace std;
int R, C;
char a[20][20];
int vis[20][20], ans[10], maxans[10], ansd;
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
void dfs(int r, int c, int pos) {
  int ok = 0;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr >= 0 && nr < R && nc >= 0 && nc < C && isdigit(a[nr][nc]) && !vis[nr][nc]) {
      ok = 1;
      vis[nr][nc] = 1;
      ans[pos] = a[nr][nc] - '0';
      dfs(nr, nc, pos + 1);
      vis[nr][nc] = 0;
    }
  }
  if (!ok) {
    if (pos < ansd)
      return;
    if (pos > ansd) {
      for (int i = 0; i < pos; i++)
        maxans[i] = ans[i];
      ansd = pos;
    } else {
      int t = 0;
      while (ans[t] == maxans[t] && t < ansd)
        t++;
      if (t == ansd)
        return;
      if (ans[t] > maxans[t]) {
        for (int i = 0; i < pos; i++)
          maxans[i] = ans[i];
      }
    }
  }
}
int main() {
  while (scanf("%d%d", &R, &C) == 2 && R) {
    ansd = 0;
    scanf(" ");
    for (int i = 0; i < R; i++) {
      char ch[20];
      fgets(ch, 20, stdin);
      for (int j = 0; j < C; j++)
        a[i][j] = ch[j];
    }
    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        if (isdigit(a[i][j])) {
          vis[i][j] = 1;
          ans[0] = a[i][j] - '0';
          dfs(i, j, 1);
          vis[i][j] = 0;
        }
    for (int i = 0; i < ansd; i++)
      printf("%d", maxans[i]);
    printf("\n");
  }
  return 0;
}