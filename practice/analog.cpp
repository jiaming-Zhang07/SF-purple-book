#include <bits/stdc++.h>
using namespace std;
vector<int> cnt(34, 0);
int get_id(char num, char type) {
  int id;
  if (type == 'm')
    id = num - '1';
  else if (type == 's')
    id = num - '1' + 9;
  else if (type == 'p')
    id = num - '1' + 18;
  else
    id = num - '1' + 27;
  return id;
}
string get_str(int id) {
  string s;
  if (id < 9)
    s = to_string(id + 1) + "m";
  else if (id < 18)
    s = to_string(id + 1 - 9) + "s";
  else if (id < 27)
    s = to_string(id + 1 - 18) + "p";
  else
    s = to_string(id + 1 - 27) + "z";
  return s;
}
bool dfs(int n) {
  if (n == 0)
    return true;
  for (int i = 0; i < 34; i++)
    if (cnt[i]) {
      if (cnt[i] >= 3) {
        cnt[i] -= 3;
        if (dfs(n - 3)) {
          cnt[i] += 3;
          return true;
        }
        cnt[i] += 3;
      }
      if (i < 27 && i % 9 < 7 && cnt[i] && cnt[i + 1] && cnt[i + 2]) {
        for (int j = 0; j < 3; j++)
          cnt[i + j]--;
        if (dfs(n - 3)) {
          for (int j = 0; j < 3; j++)
            cnt[i + j]++;
          return true;
        }
        for (int j = 0; j < 3; j++)
          cnt[i + j]++;
      }
      return false;
    }
  return false;
}
bool check() {
  for (int i = 0; i < 34; i++)
    if (cnt[i] >= 2) {
      cnt[i] -= 2;
      if (dfs(12)) {
        cnt[i] += 2;
        return true;
      }
      cnt[i] += 2;
    }
  return false;
}
void solve() {
  string s;
  cin >> s;
  for (int i = 0; i < 28; i += 2)
    cnt[get_id(s[i], s[i + 1])]++;
  if (check()) {
    cout << "Tsumo!\n";
    return;
  }
  vector<pair<int, vector<int>>> ans;
  for (int i = 0; i < 34; i++)
    if (cnt[i]) {
      cnt[i]--;
      vector<int> wait;
      for (int j = 0; j < 34; j++) {
        cnt[j]++;
        if (check()) {
          wait.push_back(j);
        }
        cnt[j]--;
      }
      if (!wait.empty())
        ans.push_back({i, wait});
      cnt[i]++;
    }
  cout << ans.size() << "\n";
  for (auto x : ans) {
    cout << get_str(x.first);
    for (auto x : x.second)
      cout << " " << get_str(x);
    cout << "\n";
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
    fill(cnt.begin(), cnt.end(), 0);
  }
  return 0;
}