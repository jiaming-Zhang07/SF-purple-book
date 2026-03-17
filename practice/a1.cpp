#include <bits/stdc++.h>
using namespace std;
struct exam {
  string name;
  int s, d, c;
  bool operator<(const exam &other) const {
    return tie(d, s) < tie(other.d, other.s);
  }
};
int ans[200005], nex[200005];
int main() {
  memset(ans, -1, sizeof(ans));
  int m, n;
  cin >> m >> n;
  vector<exam> e(n);
  for (int i = 0; i < n; i++)
    cin >> e[i].name >> e[i].s >> e[i].d >> e[i].c;
  sort(e.begin(), e.end());
  bool die = false;
  for (int i = 0; i < n; i++) {
    bool ok = false;
    for (int j = e[i].s; j <= e[i].d; j++) {
      if (nex[j])
        j = nex[j];
      if (e[i].c == 0) {
        ok = true;
        nex[e[i].s] = j;
        ans[e[i].d] = 0;
        break;
      }
      if (j == e[i].d)
        break;
      if (ans[j] == -1) {
        ans[j] = i + 1;
        e[i].c--;
      }
    }
    if (!ok) {
      die = true;
      break;
    }
  }
  if (die)
    cout << "DIE\n";
  else {
    for (int i = 1; i <= m; i++)
      if (ans[i] < 0)
        cout << "REST\n";
      else if (ans[i] == 0)
        cout << "EXAM\n";
      else
        cout << e[ans[i] - 1].name << "\n";
  }
  return 0;
}
//   for (int i = 1; i <= m; i++) {
//     if (e[l].d == i) {
//       if (e[l].c) {
//         die = true;
//         break;
//       } else {
//         ans[i] = 0;
//         l++;
//         continue;
//       }
//     }
//     for (int j = l; j < n; j++)
//       if (e[j].s <= i && e[j].c) {
//         ans[i] = j + 1;
//         e[j].c--;
//         break;
//       }
//   }