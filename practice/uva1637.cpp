#include <bits/stdc++.h>
using namespace std;
using ll = long long;
stack<char> st[9];
double d[5][5][5][5][5][5][5][5][5];
double dp() {
  double &an = d[st[0].size()][st[1].size()][st[2].size()][st[3].size()][st[4].size()][st[5].size()][st[6].size()][st[7].size()][st[8].size()];
  if (an <= 1)
    return an;
  bool win = true;
  for (int i = 0; i < 9; i++)
    if (st[i].size()) {
      win = false;
      break;
    }
  if (win)
    return an = 1;
  an = 0;
  int cnt = 0;
  for (int i = 0; i < 9; i++)
    if (!st[i].empty())
      for (int j = i + 1; j < 9; j++)
        if (!st[j].empty() && st[i].top() == st[j].top())
          cnt++;
  if (cnt == 0)
    return an;
  for (int i = 0; i < 9; i++)
    if (!st[i].empty()) {
      char t = st[i].top();
      st[i].pop();
      for (int j = i + 1; j < 9; j++)
        if (!st[j].empty() && t == st[j].top()) {
          char t2 = st[j].top();
          st[j].pop();
          an += dp() / cnt;
          st[j].push(t2);
        }
      st[i].push(t);
    }
  return an;
}
int main() {
  string s;
  while (cin >> s) {
    fill((double *)d, (double *)d + (int)pow(5, 9), 2);
    while (!st[0].empty())
      st[0].pop();
    st[0].push(s[0]);
    for (int i = 0; i < 3; i++) {
      cin >> s;
      st[0].push(s[0]);
    }
    for (int i = 1; i < 9; i++) {
      while (!st[i].empty())
        st[i].pop();
      for (int j = 0; j < 4; j++) {
        cin >> s;
        st[i].push(s[0]);
      }
    }
    cout << fixed << setprecision(6) << dp() << "\n";
  }
  return 0;
}