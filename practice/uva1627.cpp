#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
bool G[maxn][maxn];
int color[maxn];
vector<int> team[maxn][2];
int diff[maxn];
int n;
int num;
bool d[maxn][maxn * 2];
bool dfs(int c) {
  for (int i = 0; i < n; i++)
    if (!(G[c][i] && G[i][c]) && i != c) {
      if (color[i] == color[c])
        return false;
      if (!color[i]) {
        color[i] = 3 - color[c];
        team[num][color[i] - 1].push_back(i);
        if (!dfs(i))
          return false;
      }
    }
  diff[num] = (int)team[num][0].size() - (int)team[num][1].size();
  return true;
}
void print(int ans) {
  vector<int> team1, team2;
  for (int i = num - 1; i >= 0; i--) {
    int t = 1;
    if (d[i][ans - diff[i] + n]) {
      t = 0;
      ans -= diff[i];
    } else {
      ans += diff[i];
    }
    for (int j = 0; j < team[i][t].size(); j++)
      team1.push_back(team[i][t][j]);
    for (int j = 0; j < team[i][t ^ 1].size(); j++)
      team2.push_back(team[i][t ^ 1][j]);
  }
  cout << team1.size();
  for (int i = 0; i < team1.size(); i++)
    cout << " " << team1[i] + 1;
  cout << "\n";
  cout << team2.size();
  for (int i = 0; i < team2.size(); i++)
    cout << " " << team2[i] + 1;
  cout << "\n";
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    num = 0;
    cin >> n;
    memset(G, 0, sizeof(G));
    memset(color, 0, sizeof(color));
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) {
      int val;
      while (cin >> val && val) {
        G[i][val - 1] = true;
      }
    }
    for (int i = 0; i < n; i++)
      if (!color[i]) {
        color[i] = 1;
        team[num][0].clear();
        team[num][1].clear();
        team[num][color[i] - 1].push_back(i);
        if (n == 1 || !dfs(i)) {
          cout << "No solution\n";
          goto jump;
        } else
          num++;
      }
    d[0][n] = true;
    for (int i = 0; i < num; i++)
      for (int j = -n; j <= n; j++)
        if (d[i][n + j]) {
          d[i + 1][n + j + diff[i]] = d[i + 1][n + j - diff[i]] = true;
        }
    for (int i = 0; i < n; i++) {
      if (d[num][i + n]) {
        print(i);
        break;
      } else if (d[num][-i + n]) {
        print(-i);
        break;
      }
    }
  jump:;
    if (T)
      cout << "\n";
  }
  return 0;
}