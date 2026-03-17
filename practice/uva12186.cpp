#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int T;
vector<int> worker[maxn];
int dp(int b) {
  if (worker[b].size() == 0)
    return 1;
  int sum = 0;
  int m;
  int n = worker[b].size();
  if ((T * n) % 100 == 0)
    m = T * n / 100;
  else
    m = T * n / 100 + 1;
  vector<int> cnt;
  for (int i = 0; i < n; i++)
    cnt.push_back(dp(worker[b][i]));
  sort(cnt.begin(), cnt.end());
  for (int i = 0; i < m; i++)
    sum += cnt[i];
  return sum;
}
int main() {
  int n;
  while (cin >> n >> T && n) {
    int boss;
    for (int i = 1; i <= n; i++) {
      cin >> boss;
      worker[boss].push_back(i);
    }
    cout << dp(0) << "\n";
    for (int i = 0; i <= n; i++)
      worker[i].clear();
  }
  return 0;
}