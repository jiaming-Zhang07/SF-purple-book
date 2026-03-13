#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
int minv[10005], maxv[10005], v[10005], coin1[10005], coin2[10005];
void print_ans(int *d, int S) {
  while (S) {
    cout << d[S] << " ";
    S -= v[d[S]];
  }
  cout << "\n";
}
int main() {
  int S, n;
  while (cin >> n >> S) {
    minv[0] = maxv[0] = 0;
    for (int i = 1; i <= n; i++)
      cin >> v[i];
    for (int i = 1; i <= S; i++) {
      maxv[i] = -INF;
      minv[i] = INF;
    }
    for (int i = 1; i <= S; i++)
      for (int j = 1; j <= n; j++)
        if (i >= v[j]) {
          if (minv[i] > minv[i - v[j]] + 1) {
            minv[i] = minv[i - v[j]] + 1;
            coin1[i] = j;
          }
          if (maxv[i] < maxv[i - v[j]] + 1) {
            maxv[i] = maxv[i - v[j]] + 1;
            coin2[i] = j;
          }
        }
    cout << minv[S] << " " << maxv[S];
    print_ans(coin1, S);
    print_ans(coin2, S);
  }
  return 0;
}