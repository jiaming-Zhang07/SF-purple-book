#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int m, n;
  while (cin >> n >> m) {
    vector<int> e, prem;
    for (int i = 2; i <= m / i; i++)
      if (m % i == 0) {
        prem.push_back(i);
        int c = 0;
        while (m % i == 0) {
          m /= i;
          c++;
        }
        e.push_back(c);
      }
    if (m > 1) {
      prem.push_back(m);
      e.push_back(1);
    }
    int cnt = 0;
    n--;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      int t = n - i + 1;
      for (int i = 0; i < prem.size(); i++)
        while (t % prem[i] == 0) {
          e[i]--;
          t /= prem[i];
        }
      t = i;
      for (int i = 0; i < prem.size(); i++)
        while (t % prem[i] == 0) {
          e[i]++;
          t /= prem[i];
        }
      bool ok = true;
      for (int x : e)
        if (x > 0) {
          ok = false;
          break;
        }
      if (ok) {
        cnt++;
        ans.push_back(i + 1);
      }
    }
    cout << cnt << "\n";
    for (int i = 0; i + 1 < ans.size(); i++)
      cout << ans[i] << " ";
    if (cnt)
      cout << ans.back();
    cout << "\n";
  }
  return 0;
}