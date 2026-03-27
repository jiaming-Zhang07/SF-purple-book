#include <bits/stdc++.h>
using namespace std;
struct xy {
  int x, y;
} a[200005];
int main() {
  map<int, int> x, y;
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    x[a[i].x]++;
    y[a[i].y]++;
  }
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += (long long)(x[a[i].x] - 1) * (y[a[i].y] - 1);
  }
  cout << cnt << "\n";
}
