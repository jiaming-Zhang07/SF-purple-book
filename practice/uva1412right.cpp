#include <bits/stdc++.h>
using namespace std;
struct stock {
  double v[105];
  string name;
  int s, k;
} st[10];
int m, n, k;
const int maxstate = 15000;
double d[105][maxstate];
vector<vector<int>> state;
map<vector<int>, int> ID;
int buy_next[maxstate][10], sell_next[maxstate][10];
int pre[105][maxstate], op[105][maxstate];
void update(int oldh, int day, int h, double v, int o) {
  if (v > d[day][h]) {
    d[day][h] = v;
    pre[day][h] = oldh;
    op[day][h] = o;
  }
}
void print(int day, int h) {
  if (day == 0)
    return;
  print(day - 1, pre[day][h]);
  int o = op[day][h];
  if (o == 0)
    cout << "HOLD\n";
  else if (o > 0)
    cout << "BUY " << st[o - 1].name << "\n";
  else
    cout << "SELL " << st[-o - 1].name << "\n";
}
void dfs(int i, vector<int> &v, int tot) {
  if (i == n) {
    ID[v] = state.size();
    state.push_back(v);
  } else
    for (int j = 0; j <= st[i].k && tot + j <= k; j++) {
      v[i] = j;
      dfs(i + 1, v, tot + j);
    }
}
void init() {
  state.clear();
  vector<int> v(n);
  ID.clear();
  dfs(0, v, 0);
  for (int s = 0; s < state.size(); s++) {
    int tot = 0;
    for (int i = 0; i < n; i++) {
      tot += state[s][i];
      buy_next[s][i] = sell_next[s][i] = -1;
    }
    for (int i = 0; i < n; i++) {
      if (state[s][i] < st[i].k && tot < k) {
        vector<int> temp = state[s];
        temp[i]++;
        buy_next[s][i] = ID[temp];
      }
      if (state[s][i] > 0) {
        vector<int> temp = state[s];
        temp[i]--;
        sell_next[s][i] = ID[temp];
      }
    }
  }
}
int main() {
  int kase = 0;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  double c;
  while (cin >> c >> m >> n >> k) {
    for (int i = 0; i < n; i++) {
      cin >> st[i].name >> st[i].s >> st[i].k;
      for (int j = 0; j < m; j++)
        cin >> st[i].v[j];
    }
    init();
    for (int i = 0; i <= m; i++)
      for (int s = 0; s < state.size(); s++)
        d[i][s] = -1;
    d[0][0] = c;
    for (int day = 0; day < m; day++)
      for (int s = 0; s < state.size(); s++) {
        if (d[day][s] < 0)
          continue;
        double v = d[day][s];
        update(s, day + 1, s, v, 0);
        for (int i = 0; i < n; i++) {
          if (buy_next[s][i] >= 0 && v + 1e-3 >= st[i].v[day] * st[i].s)
            update(s, day + 1, buy_next[s][i], v - st[i].v[day] * st[i].s, i + 1);
          if (sell_next[s][i] >= 0)
            update(s, day + 1, sell_next[s][i], v + st[i].v[day] * st[i].s, -i - 1);
        }
      }
    if (kase++)
      cout << "\n";
    cout << fixed << setprecision(2) << d[m][0] << "\n";
    print(m, 0);
  }
  return 0;
}