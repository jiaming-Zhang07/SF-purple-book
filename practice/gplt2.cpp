#include <bits/stdc++.h>
using namespace std;
struct exam {
  string name;
  int s, d, c;
  bool operator<(const exam &other) const {
    return d > other.d;
  }
};
vector<int> release[200005];
int main() {
  int m, n;
  cin >> m >> n;
  vector<string> ans(m + 1, "REST\n");
  vector<exam> e(n + 1);
  vector<int> ex(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> e[i].name >> e[i].s >> e[i].d >> e[i].c;
    release[e[i].s].push_back(i);
    ex[e[i].d] = i;
  }
  bool die = false;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < release[i].size(); j++)
      pq.push({e[release[i][j]].d, release[i][j]});
    if (ex[i]) {
      if (e[ex[i]].c > 0) {
        die = true;
        break;
      }
      ans[i] = "EXAM\n";
      continue;
    }
    if (!pq.empty()) {
      int t = pq.top().second;
      pq.pop();
      ans[i] = e[t].name + "\n";
      e[t].c--;
      if (e[t].c > 0)
        pq.push({e[t].d, t});
    }
  }
  if (die)
    cout << "DIE\n";
  else {
    for (int i = 1; i <= m; i++)
      cout << ans[i];
  }
  return 0;
}
