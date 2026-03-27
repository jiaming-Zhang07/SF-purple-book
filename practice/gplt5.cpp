#include <bits/stdc++.h>
using namespace std;
int rans[20];
int a[20], ans[20];
long long sum = 0;
int n;
bool great(int *a, int *b) {
  int i;
  for (i = 0; a[i] != 0 && b[i] != 0; i++)
    if (a[i] != b[i]) {
      return a[i] > b[i];
    }
  if (a[i] != 0)
    return true;
  return false;
}
bool first = true;
void dfs(int pos, long long s, int d) {
  if (s > sum)
    return;
  if (s == sum) {
    ans[d] = 0;
    if (first || !great(ans, rans)) {
      copy(ans, ans + d + 1, rans);
      first = false;
    }
    return;
  }
  for (int i = pos; i < n; i++) {
    ans[d] = a[i];
    dfs(i + 1, s + a[i], d + 1);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sum /= 2;
  dfs(0, 0, 0);
  cout << sum << "\n";
  cout << rans[0];
  for (int i = 1; rans[i] != 0; i++)
    cout << " " << rans[i];
  cout << "\n";
  return 0;
}