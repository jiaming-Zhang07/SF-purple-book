#include <bits/stdc++.h>
using namespace std;
struct rec {
  int w, h;
} r[1005];
bool g[1005][1005];
int d[1005], n;
bool first = true;
int dp(int i) {
  int &ans = d[i];
  if (ans > 0)
    return ans;
  ans = 1;
  for (int j = 1; j <= n; j++)
    if (g[i][j])
      ans = max(ans, dp(j) + 1);
  return ans;
}
void print_ans(int i) {
  if (!first)
    cout << " ";
  else
    first = false;
  cout << i;
  for (int j = 1; j <= n; j++)
    if (g[i][j] && d[i] == d[j] + 1) {
      print_ans(j);
      break;
    }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> r[i].w >> r[i].h;
    if (r[i].w > r[i].h)
      swap(r[i].w, r[i].h);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (r[i].w < r[j].w && r[i].h < r[j].h)
        g[i][j] = true;
  int maxp = 0;
  for (int i = 1; i <= n; i++)
    maxp = max(dp(i), maxp);
  cout << maxp << "\n";
  for (int i = 1; i <= n; i++)
    if (dp(i) == maxp) {
      print_ans(i);
      break;
    }
  return 0;
}