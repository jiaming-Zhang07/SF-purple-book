#include <bits/stdc++.h>
using namespace std;
string s[205];
int cnt[205];
int main() {
  int d, n, x;
  cin >> d >> n >> x;
  for (int i = 0; i < d; i++) {
    cin >> cnt[i] >> ws;
    getline(cin, s[i]);
  }
  string str;
  getline(cin, str);
  vector<string> v;
  int t = 0;
  while (t < str.size()) {
    bool ok = false;
    for (int i = 0; i < d; i++)
      if (str.substr(t, s[i].size()) == s[i] && str[t + s[i].size()] == ' ') {
        v.push_back(s[i]);
        t += s[i].size() + 1;
        ok = true;
        break;
      }
    if (!ok) {
      stringstream ss(str.substr(t));
      string st;
      ss >> st;
      v.push_back(st);
      t += st.size() + 1;
    }
  }
  int a = v.size();
  string h;
  cin >> h;
  string tt;
  int cnt = 0;
  stringstream ss(str);
  while (ss >> tt)
    if (tt == h)
      cnt++;
  printf("%.10f\n", (double)x * cnt / a);
}
