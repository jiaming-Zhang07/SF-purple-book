#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> sta[55], sum(2505);
int main() {
  int n, kase = 0;
  while (cin >> n && n) {
    int cnt = 0, s = 0;
    for (int i = 0; i < n; i++) {
      int h;
      cin >> h;
      sta[i].resize(h);
      for (int j = 0; j < h; j++) {
        cin >> sta[i][j];
        sum[cnt++] = sta[i][j];
      }
    }
    sort(sum.begin(), sum.begin() + cnt);
    for (int i = 0; i < n; i++) {
      auto it = find(sum.begin(), sum.begin() + cnt, sta[i][0]);
      it++;
      for (int j = 1; j < sta[i].size(); j++, it++)
        if (sta[i][j] != *it) {
          s++;
          it = find(sum.begin(), sum.begin() + cnt, sta[i][j]);
        }
    }
    printf("Case %d: %d\n", ++kase, s + (n + s) - 1);
  }
  return 0;
}