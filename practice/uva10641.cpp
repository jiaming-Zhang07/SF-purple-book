#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e15;
int n, m;
struct dot {
  ll x, y;
  int l, r;
  ll c;
} stad[35], light[1005];
ll d[70];
bool lightened(int i, int j, int base) {
  return (stad[i].x - light[base].x) * (stad[j].y - light[base].y) - (stad[j].x - light[base].x) * (stad[i].y - light[base].y) < 0;
}
int S;
ll dp(int s) {
  if (s - S >= n)
    return 0;
  ll &ans = d[s];
  if (ans != -1)
    return ans;
  ans = INF;
  for (int i = 0; i < m; i++) {
    if (s >= n && light[i].r < n && light[i].l + n <= s && light[i].r + n >= s)
      ans = min(ans, dp(light[i].r + n + 1) + light[i].c);
    if (light[i].l <= s && light[i].r >= s)
      ans = min(ans, dp(light[i].r + 1) + light[i].c);
  }
  return ans;
}
int main() {
  while (cin >> n && n) {
    for (int i = 0; i < n; i++)
      cin >> stad[i].x >> stad[i].y;
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> light[i].x >> light[i].y >> light[i].c;
      int r = -1, l = 0, flag = 0, broken = 0;
      for (int k = 0; k < n; k++)
        if (lightened(k, (k + 1) % n, i)) {
          if (!flag) {
            l = k;
            flag = 1;
          }
          if (!broken)
            r = k;
          if (broken) {
            r = r + n;
            l = k;
            break;
          }
        } else if (flag)
          broken = 1;
      if (r < l)
        r += n;
      light[i].l = l;
      light[i].r = r;
    }
    ll Ans = INF;
    for (int i = 0; i < n; i++) {
      memset(d, -1, sizeof(d));
      S = i;
      Ans = min(Ans, dp(i));
    }
    if (Ans == INF)
      cout << "Impossible.\n";
    else
      cout << Ans << "\n";
  }
  return 0;
}