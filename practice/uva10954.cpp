#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n && n) {
    long long ans = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    int t;
    for (int i = 0; i < n; i++) {
      cin >> t;
      pq.push(t);
    }
    while (pq.size() > 1) {
      long long sum = 0;
      for (int j = 0; j < 2; j++) {
        sum += pq.top();
        pq.pop();
      }
      pq.push(sum);
      ans += sum;
    }
    cout << ans << endl;
  }
  return 0;
}