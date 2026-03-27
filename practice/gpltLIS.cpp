#include <bits/stdc++.h>
using namespace std;
const int maxn = 20005;
vector<int> pos[maxn];
vector<int> g;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int x;
  for (int i = 1; i <= 5 * n; i++) {
    cin >> x;
    pos[x].push_back(i);
    if (pos[x].size() == 5)
      reverse(pos[x].begin(), pos[x].end());
  }
  int val;
  for (int i = 0; i < 5 * n; i++) {
    cin >> val;
    for (int j = 0; j < pos[val].size(); j++) {
      int m = pos[val][j];
      int t = lower_bound(g.begin(), g.end(), m) - g.begin();
      if (t == g.size())
        g.push_back(m);
      else
        g[t] = m;
    }
  }
  cout << g.size() << "\n";
  return 0;
}