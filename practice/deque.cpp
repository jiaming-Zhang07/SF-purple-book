#include <bits/stdc++.h>
using namespace std;
int main() {
  deque<int> d;
  int n, q, t;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> t;
    d.push_back(t);
  }
  for (int i = 0; i < q; i++) {
    cin >> t;
    if (t == 1) {
      d.push_back(d.front());
      d.pop_front();
    } else {
      d.push_front(d.back());
      d.pop_back();
    }
  }
  for (int i = 0; i < n; i++)
    cout << d[i] << " ";
  cout << "\n";
  return 0;
}