#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll freq;
    cin >> freq;
    pq.push(freq);
  }
  ll total_wpl = 0;
  while (pq.size() > 1) {
    ll t1 = pq.top();
    pq.pop();
    ll t2 = pq.top();
    pq.pop();
    ll sum = t1 + t2;
    pq.push(sum);
    total_wpl += sum;
  }
  printf("%lld", total_wpl);
  return 0;
}