#include <bits/stdc++.h>
using namespace std;
struct node {
  int v, ind;
  bool operator<(const node &other) const {
    return v > other.v;
  }
} a[100005];
int b[100005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  while (cin >> n) {
    memset(b, -1, sizeof(b));
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i].v;
      a[i].ind = i;
      sum += a[i].v;
    }
    if (sum & 1) {
      cout << "No" << "\n";
      continue;
    }
    cout << "Yes" << "\n";
    sum /= 2;
    sort(a, a + n);
    for (int i = 0; i < n && sum > 0; i++)
      if (a[i].v <= sum) {
        sum -= a[i].v;
        b[a[i].ind] = 1;
      }
    cout << b[0];
    for (int i = 1; i < n; i++)
      cout << " " << b[i];
    cout << "\n";
  }
  return 0;
}