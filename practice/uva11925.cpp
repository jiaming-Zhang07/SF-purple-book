#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n && n) {
    int t;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
      cin >> t;
      dq.push_back(t);
    }
    string ans = "";
    while (!is_sorted(dq.begin(), dq.end())) {
      ans += "2";
      dq.push_front(dq.back());
      dq.pop_back();
      if (dq[0] > dq[1] && !(dq[0] == n && dq[1] == 1)) {
        ans += "1";
        swap(dq[0], dq[1]);
      }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
  return 0;
}