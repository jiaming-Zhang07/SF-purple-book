#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxs = 50 * 10 + 52 + 5;
string dp[maxs][25];
struct trans {
  int tar, empty;
};
vector<trans> tr[maxs];
map<string, int> id;
int ns;
string str[maxs];
int ID(string s) {
  if (!id.count(s)) {
    str[ns] = s;
    id[s] = ns++;
  }
  return id[s];
}
int head[maxs], tail[maxs];
void add(string s) {
  int d = ID(s);
  int h = ID(s.substr(0, 1)), w = ID(s.substr(1));
  tr[h].push_back({d, w});
  tr[w].push_back({d, h});
  head[d] = h;
  tail[d] = w;
}
struct node {
  int id;
  string s;
  bool operator<(const node &other) const {
    return s > other.s;
  }
};
bool vis[maxs];
void search(int len) {
  memset(vis, 0, sizeof(vis));
  priority_queue<node> pq;
  for (int i = 0; i < ns; i++)
    if (dp[i][len] != "-")
      pq.push({i, dp[i][len]});
  while (!pq.empty()) {
    int id = pq.top().id;
    pq.pop();
    if (vis[id])
      continue;
    vis[id] = true;
    for (int i = 0; i < tr[id].size(); i++) {
      int tar = tr[id][i].tar, empty = tr[id][i].empty;
      if (dp[empty][0] == "" && (dp[tar][len] == "-" || dp[tar][len] > dp[id][len])) {
        dp[tar][len] = dp[id][len];
        pq.push({tar, dp[tar][len]});
      }
    }
  }
}
string min(string s1, string s2) {
  if (s1 == "-")
    return s2;
  else
    return s1 < s2 ? s1 : s2;
}
bool ok(string s) {
  for (int i = 0; i < s.size(); i++)
    if (!(s[i] >= 'a' && s[i] <= 'z'))
      return false;
  return true;
}
int main() {
  int n, L;
  while (cin >> n && n) {
    for (int i = 0; i < maxs; i++)
      tr[i].clear();
    ns = 0;
    id.clear();
    cin >> L;
    string s;
    ID("");
    for (int i = 0; i < n; i++) {
      cin >> s;
      string s1 = s.substr(0, 1), s2 = s.substr(2);
      int left = ID(s1), right = ID(s2);
      tr[right].push_back({left, 0});
      for (int k = 0; k + 1 < s2.size(); k++)
        add(s2.substr(k));
    }
    for (int i = 0; i < ns; i++)
      for (int j = 0; j <= L; j++)
        dp[i][j] = "-";
    dp[0][0] = "";
    for (int l = 0; l <= L; l++) {
      for (int i = 0; i < ns; i++) {
        if (str[i].size() == l && ok(str[i]))
          dp[i][l] = str[i];
        if (str[i].size() < 2)
          continue;
        int d1 = head[i], d2 = tail[i];
        for (int k = 1; k < l; k++)
          if (dp[d1][k] != "-" && dp[d2][l - k] != "-") {
            dp[i][l] = min(dp[i][l], dp[d1][k] + dp[d2][l - k]);
          }
      }
      search(l);
    }
    cout << dp[ID("S")][L] << "\n";
  }
  return 0;
}
