#include <bits/stdc++.h>
using namespace std;
int p[505];
int last[505];
int m, k;
int solve(long long maxp) {
  long long done = 0;
  int ans = 1;
  for (int i = 0; i < m; i++)
    if (done + p[i] > maxp) {
      ans++;
      done = p[i];
    } else
      done += p[i];
  return ans;
}
void print(long long maxp) {
  long long done = 0;
  int remain = k;
  for (int i = m - 1; i >= 0; i--) {
    if (done + p[i] > maxp || i + 1 == remain - 1) {
      last[i] = 1;
      done = p[i];
      remain--;
    } else
      done += p[i];
  }
  for (int i = 0; i < m - 1; i++) {
    cout << p[i] << " ";
    if (last[i])
      cout << "/ ";
  }
  cout << p[m - 1] << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(last, 0, sizeof(last));
    cin >> m >> k;
    int maxp = -1;
    long long tot = 0;
    for (int i = 0; i < m; i++) {
      cin >> p[i];
      maxp = max(p[i], maxp);
      tot += p[i];
    }
    long long l = maxp, r = tot;
    while (l < r) {
      long long t = l + (r - l) / 2;
      if (solve(t) <= k)
        r = t;
      else
        l = t + 1;
    }
    print(l);
  }
  return 0;
}