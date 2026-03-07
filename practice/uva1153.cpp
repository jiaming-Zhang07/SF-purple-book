#include <bits/stdc++.h>
using namespace std;
struct order {
  int num, due;
  bool operator<(const order &other) const {
    return num < other.num;
  }
  bool operator>(const order &other) const {
    return due < other.due;
  }
} a[800005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i].num >> a[i].due;
    }
    sort(a, a + n, greater<order>());
    priority_queue<int> pq;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (sum + a[i].num <= a[i].due) {
        pq.push(a[i].num);
        sum += a[i].num;
      } else {
        if (!pq.empty() && pq.top() > a[i].num) {
          sum -= pq.top() - a[i].num;
          pq.pop();
          pq.push(a[i].num);
        }
      }
    }
    cout << pq.size() << "\n";
    if (T)
      cout << "\n";
  }
  return 0;
}