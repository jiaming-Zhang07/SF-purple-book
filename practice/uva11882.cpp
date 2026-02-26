#include <bits/stdc++.h>
using namespace std;
struct digit {
  int r, c, num;
  bool operator<(const digit &other) const {
    return num > other.num;
  }
} dig[230];
int R, C;
char a[20][20];
int vis[20][20], ans[250], maxans[250], ansd;
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
int h(int r, int c) {
  static int bvis[20][20];
  int cnt = 0;
  static pair<int, int> p[230];
  static int t = 0;
  t++;
  int head = 0, tail = 0;
  p[tail++] = {r, c};
  while (head < tail) {
    pair<int, int> p2 = p[head++];
    for (int i = 0; i < 4; i++) {
      int nr = p2.first + dr[i], nc = p2.second + dc[i];
      if (nr >= 0 && nr < R && nc >= 0 && nc < C && isdigit(a[nr][nc]) && !vis[nr][nc] && bvis[nr][nc] != t) {
        bvis[nr][nc] = t;
        p[tail++] = {nr, nc};
        cnt++;
      }
    }
  }
  return cnt;
}
bool few(int pos) {
  int t = 0;
  while (maxans[t] == ans[t] && t < pos)
    t++;
  if (t == pos || ans[t] > maxans[t])
    return false;
  return true;
}
void dfs(int r, int c, int pos) {
  int ok = 0;
  int hh = h(r, c);
  if (pos + hh < ansd || (ansd == pos + hh && few(pos)))
    return;
  digit st[4];
  int t = 0;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr >= 0 && nr < R && nc >= 0 && nc < C && isdigit(a[nr][nc]) && !vis[nr][nc]) {
      ok = 1;
      st[t++] = {nr, nc, a[nr][nc] - '0'};
    }
  }
  sort(st, st + t);
  for (int i = 0; i < t; i++) {
    vis[st[i].r][st[i].c] = 1;
    ans[pos] = st[i].num;
    dfs(st[i].r, st[i].c, pos + 1);
    vis[st[i].r][st[i].c] = 0;
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
    memset(maxans, 0, sizeof(maxans));
    int mad = 0;
    for (int i = 0; i < R; i++) {
      char ch[20];
      scanf("%s", ch);
      for (int j = 0; j < C; j++) {
        a[i][j] = ch[j];
        if (isdigit(ch[j]))
          dig[mad++] = {i, j, a[i][j] - '0'};
      }
    }
    sort(dig, dig + mad);
    for (int i = 0; i < mad; i++) {
      if (ansd == mad && maxans[0] > dig[i].num)
        continue;
      vis[dig[i].r][dig[i].c] = 1;
      ans[0] = dig[i].num;
      dfs(dig[i].r, dig[i].c, 1);
      vis[dig[i].r][dig[i].c] = 0;
    }
    for (int i = 0; i < ansd; i++)
      printf("%d", maxans[i]);
    printf("\n");
  }
  return 0;
}