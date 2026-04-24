#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e7 + 5;
int ans[maxn];
void init() {
  for (int i = 1; i <= maxn; i++)
    for (int a = i * 2; a <= maxn; a += i) {
      if (((a - i) ^ a) == i)
        ans[a]++;
    }
  for (int i = 2; i <= maxn; i++)
    ans[i] += ans[i - 1];
}
int main() {
  int T, kase = 0;
  cin >> T;
  init();
  while (T--) {
    int n;
    cin >> n;
    printf("Case %d: %d\n", ++kase, ans[n]);
  }
  return 0;
}