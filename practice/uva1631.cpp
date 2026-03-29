#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1005, INF = 1 << 30;
int target[maxn], s[maxn];
char temp1[maxn], temp2[maxn];
int n, d[maxn][10][10];
int dp(int p, int c1, int c2) {
  if (p == n)
    return 0;
  int &ans = d[p][c1][c2];
  if (ans != -1)
    return ans;
  ans = INF;
  int n1 = (target[p] - c1 + 10) % 10, n2 = (c1 - target[p] + 10) % 10;
  for (int i = 0; i <= n1; i++)
    for (int j = 0; j <= i; j++)
      ans = min(ans, n1 + dp(p + 1, (c2 + i) % 10, (s[p + 2] + j) % 10));
  for (int i = 0; i <= n2; i++)
    for (int j = 0; j <= i; j++)
      ans = min(ans, n2 + dp(p + 1, (c2 - i + 10) % 10, (s[p + 2] - j + 10) % 10));
  return ans;
}
int main() {
  while (cin >> temp1 >> temp2) {
    for (int i = 0; temp1[i] != '\0'; i++)
      s[i] = temp1[i] - '0';
    for (int i = 0; temp2[i] != '\0'; i++)
      target[i] = temp2[i] - '0';
    memset(d, -1, sizeof(d));
    n = strlen(temp1);
    cout << dp(0, s[0], s[1]) << "\n";
  }
  return 0;
}