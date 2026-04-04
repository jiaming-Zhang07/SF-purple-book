#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool have(const vector<int> &v, int v1, int v2) {
  for (int i = 0; i + 1 < v.size(); i++)
    if (v[i] == v1 && v[i + 1] == v2)
      return true;
  return false;
}
int main() {
  int n, kase = 0;
  while (cin >> n && n) {
    vector<int> sta[55];
    set<int> all;
    map<int, int> cnt;
    int B = 0;
    for (int i = 0; i < n; i++) {
      int h;
      cin >> h;
      int last = -1;
      for (int j = 0; j < h; j++) {
        int t;
        cin >> t;
        if (t != last) {
          B++;
          cnt[t]++;
          sta[i].push_back(t);
          all.insert(t);
          last = t;
        }
      }
    }
    vector<int> v(all.begin(), all.end());
    int pre_none = 0;
    vector<int> pre(n, -1);
    for (int k = 0; k + 1 < v.size(); k++) {
      vector<int> nex(n, -1);
      int nex_none = pre_none;
      int v1 = v[k], v2 = v[k + 1];
      for (int i = 0; i < n; i++)
        if (pre[i] != -1) {
          nex_none = max(nex_none, pre[i]);
        }
      for (int i = 0; i < n; i++)
        if (have(sta[i], v1, v2)) {
          nex[i] = pre_none + 1;
          for (int j = 0; j < n; j++)
            if (pre[j] != -1) {
              if (j == i && cnt[v1] > 1)
                nex[i] = max(nex[i], pre[i]);
              else
                nex[i] = max(nex[i], pre[j] + 1);
            }
        }
      pre_none = nex_none;
      pre = nex;
    }
    int maxp = pre_none;
    for (int i = 0; i < n; i++)
      maxp = max(maxp, pre[i]);
    int ans = 2 * B - n - 2 * maxp - 1;
    printf("Case %d: %d\n", ++kase, ans);
  }
  return 0;
}