#include <bits/stdc++.h>
using namespace std;
int op;
vector<int> world[105];
int pa[105];
int cnt = 1, now;
int main() {
  int q;
  pa[0] = 0;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &op);
    if (op == 1) {
      int p, v;
      scanf("%d%d", &p, &v);
      if (v > 0) {
        world[now].insert(world[now].begin() + p, v);
      } else {
        world[now].insert(world[now].begin() + p, -cnt++);
        pa[cnt - 1] = now;
      }
    } else if (op == 2) {
      int p;
      scanf("%d", &p);
      world[now].erase(world[now].begin() + p - 1);
    } else if (op == 3) {
      int p;
      scanf("%d", &p);
      if (p == 0) {
        now = pa[now];
        continue;
      }
      if (world[now][p - 1] > 0)
        continue;
      now = -world[now][p - 1];
    } else {
      printf("{");
      bool first = true;
      for (int i = 0; i < world[now].size(); i++) {
        if (!first)
          cout << " ";
        else
          first = false;
        if (world[now][i] < 0)
          printf("[]");
        else
          printf("%d", world[now][i]);
      }
      printf("}\n");
    }
  }
  return 0;
}