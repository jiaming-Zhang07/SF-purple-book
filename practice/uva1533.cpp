#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct Move {
  int from, to, d;
} mov[(1 << 15) + 5];
struct state {
  int from, to, sta;
  bool operator<(const state &other) const {
    return tie(from, to) < tie(other.from, other.to);
  }
};
int fa[(1 << 15) + 5], vis[(1 << 15) + 5];
int G[16][6][5] = {{{2, 4, 7, 11}, {3, 6, 10, 15}}, {{5, 9, 14}, {4, 7, 11}}, {{5, 8, 12}, {6, 10, 15}}, {{2, 1}, {5, 6}, {7, 11}, {8, 13}}, {{8, 12}, {9, 14}}, {{9, 13}, {10, 15}, {5, 4}, {3, 1}}, {{8, 9, 10}, {4, 2, 1}}, {{5, 3}, {9, 10}}, {{5, 2}, {8, 7}}, {{6, 3, 1}, {9, 8, 7}}, {{7, 4, 2, 1}, {12, 13, 14, 15}}, {{13, 14, 15}, {8, 5, 3}}, {{12, 11}, {8, 4}, {9, 6}, {14, 15}}, {{9, 5, 2}, {13, 12, 11}}, {{14, 13, 12, 11}, {10, 6, 3, 1}}};
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int ok = 0;
    memset(fa, -1, sizeof(fa));
    memset(vis, 0, sizeof(vis));
    int goal;
    scanf("%d", &goal);
    goal--;
    int sta = (~(1 << goal)) & ((1 << 15) - 1);
    vis[sta] = 1;
    vector<int> v;
    v.push_back(sta);
    int f = 0, e = 1;
    while (f < e) {
      int st = v[f++];
      if (st == 1 << goal) {
        vector<int> ans;
        printf("%d\n", mov[f - 1].d);
        f--;
        while (fa[f] != -1) {
          ans.push_back(f);
          f = fa[f];
        }
        for (int i = ans.size() - 1; i >= 0; i--)
          printf("%d %d%c", mov[ans[i]].from, mov[ans[i]].to, i == 0 ? '\n' : ' ');
        ok = 1;
        break;
      }
      vector<state> nsta;
      for (int i = 0; i < 15; i++)
        if (st & 1 << i) {
          for (int j = 0; G[i][j][0]; j++) {
            int k = 0;
            while (G[i][j][k] && (st & 1 << (G[i][j][k] - 1)))
              k++;
            if (G[i][j][k] == 0 || k == 0)
              continue;
            int tmp = st;
            for (int m = 0; m < k; m++)
              tmp &= ~(1 << (G[i][j][m] - 1));
            tmp &= ~(1 << i);
            tmp |= 1 << (G[i][j][k] - 1);
            nsta.push_back({i + 1, G[i][j][k], tmp});
          }
        }
      sort(nsta.begin(), nsta.end());
      for (int i = 0; i < nsta.size(); i++) {
        if (vis[nsta[i].sta])
          continue;
        vis[nsta[i].sta] = 1;
        fa[e] = f - 1;
        mov[e] = Move{nsta[i].from, nsta[i].to, mov[f - 1].d + 1};
        v.push_back(nsta[i].sta);
        e++;
      }
    }
    if (!ok)
      printf("IMPOSSIBLE\n");
  }
}
