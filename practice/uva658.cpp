#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct op {
  int t;
  string s0, s1;
} o[105];
struct sta {
  int t;
  int s;
  bool operator<(const sta &b) const {
    return t > b.t;
  }
};
int mark[1 << 20], dist[1 << 20];
int main() {
  int n, m, kase = 0;
  while (cin >> n >> m && n) {
    memset(dist, 0x3f, sizeof(dist));
    memset(mark, 0, sizeof(mark));
    priority_queue<sta> pq;
    for (int i = 0; i < m; i++) {
      cin >> o[i].t >> o[i].s0 >> o[i].s1;
    }
    dist[(1 << n) - 1] = 0;
    pq.push({0, (1 << n) - 1});
    int ans = -1;
    while (!pq.empty()) {
      sta temp = pq.top();
      pq.pop();
      int &t = temp.t;
      int &s = temp.s;
      if (mark[s])
        continue;
      mark[s] = 1;
      if (s == 0) {
        ans = t;
        break;
      }
      for (int i = 0; i < m; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++)
          if ((o[i].s0[j] == '+' && ((s >> j) & 1) == 0) || (o[i].s0[j] == '-' && ((s >> j) & 1) == 1)) {
            ok = false;
            break;
          }
        if (!ok)
          continue;
        int temps = s;
        for (int j = 0; j < n; j++)
          if (o[i].s1[j] == '+')
            temps |= 1 << j;
          else if (o[i].s1[j] == '-')
            temps &= ~(1 << j);
        if (t + o[i].t < dist[temps]) {
          dist[temps] = t + o[i].t;
          pq.push({t + o[i].t, temps});
        }
      }
    }
    cout << "Product " << ++kase << "\n";
    if (ans == -1)
      cout << "Bugs cannot be fixed.\n";
    else
      printf("Fastest sequence takes %d seconds.\n", ans);
    cout << "\n";
  }
  return 0;
}