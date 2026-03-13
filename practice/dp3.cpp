#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
int n;
int v[105], d1[10005], d2[10005];
int solve1(int S) {
  if (d1[S] != -1)
    return d1[S];
  int &ans = d1[S];
  ans = INF;
  for (int i = 1; i <= n; i++)
    if (S >= v[i])
      ans = min(ans, solve1(S - v[i]) + 1);
  return ans;
}
int solve2(int S) {
  if (d2[S] != -1)
    return d2[S];
  int &ans = d2[S];
  ans = -2;
  for (int i = 1; i <= n; i++)
    if (S >= v[i]) {
      int res = solve2(S - v[i]);
      if (res != -2)
        ans = max(ans, res + 1);
    }
  return ans;
}
bool first;
void print_ans(int *d, int S) {
  if (S == 0)
    return;
  for (int i = 1; i <= n; i++)
    if (S >= v[i] && d[S] == d[S - v[i]] + 1) {
      if (!first)
        cout << " ";
      else
        first = false;
      cout << i;
      print_ans(d, S - v[i]);
      break;
    }
}
int main() {
  int S;
  while (cin >> n >> S) {
    memset(d1, -1, sizeof(d1));
    memset(d2, -1, sizeof(d2));
    d1[0] = d2[0] = 0;
    for (int i = 1; i <= n; i++)
      cin >> v[i];
    int result = solve1(S);
    if (result >= INF)
      cout << "impossible\n";
    else {
      cout << result << "\n";
      first = true;
      print_ans(d1, S);
      cout << "\n";
    }
    result = solve2(S);
    if (result < 0)
      cout << "impossible\n";
    else {
      cout << result << "\n";
      first = true;
      print_ans(d2, S);
      cout << "\n";
    }
  }
  return 0;
}