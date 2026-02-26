#include <bits/stdc++.h>
using namespace std;
struct leader {
  int r, c, size;
} lead[30];
int n, k, used[30];
char ans[25][25];
int num;
void dfs(int r, int c) {
  if (r == n)
    throw 1;
  if (c == n) {
    dfs(r + 1, 0);
    return;
  }
  if (isalpha(ans[r][c])) {
    dfs(r, c + 1);
    return;
  }
  for (int li = 0; li < k; li++)
    if (!used[li] && lead[li].r >= r && lead[li].c >= c) {
      leader l = lead[li];
      for (int R = 1; R <= l.size; R++)
        if (l.size % R == 0) {
          int C = l.size / R;
          if (r + R - 1 < l.r || c + C - 1 < l.c || r + R > n || c + C > n)
            continue;
          for (int i = r; i < r + R; i++)
            for (int j = c; j < c + C; j++)
              if ((isdigit(ans[i][j]) && (i != l.r || j != l.c)) || isalpha(ans[i][j]))
                goto jump;
          for (int i = r; i < r + R; i++)
            for (int j = c; j < c + C; j++)
              ans[i][j] = 'A' + li;
          used[li] = 1;
          dfs(r, c + 1);
          used[li] = 0;
          for (int i = r; i < r + R; i++)
            for (int j = c; j < c + C; j++) {
              if (i == l.r && j == l.c) {
                ans[i][j] = l.size + '0';
                continue;
              }
              ans[i][j] = '.';
            }
        jump:;
        }
    }
}
int main() {
  while (scanf("%d%d", &n, &k) == 2 && n) {
    memset(used, 0, sizeof(used));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", ans[i]);
      for (int j = 0; j < n; j++)
        if (isdigit(ans[i][j]))
          lead[cnt++] = {i, j, ans[i][j] - '0'};
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