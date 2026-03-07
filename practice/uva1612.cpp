#include <bits/stdc++.h>
using namespace std;
int score[17000][8], ran[17000], n;
int solve() {
  int last_r = ran[0] - 1, last_s = score[last_r][7];
  for (int i = 1; i < n; i++) {
    int r = ran[i] - 1;
    int ind;
    if (r < last_r) {
      ind = lower_bound(score[r], score[r] + 8, last_s) - score[r];
    } else
      ind = upper_bound(score[r], score[r] + 8, last_s) - score[r];
    if (ind == 0)
      return -1;
    last_s = score[r][ind - 1];
    last_r = r;
  }
  return last_s;
}
int main() {
  int kase = 0;
  while (cin >> n && n) {
    printf("Case %d: ", ++kase);
    for (int i = 0; i < n; i++) {
      int tscore[3];
      for (int j = 0; j < 3; j++) {
        double t;
        scanf("%lf", &t);
        tscore[j] = t * 100 + 0.5;
      }
      for (int k = 0; k < 8; k++) {
        score[i][k] = 0;
        for (int j = 0; j < 3; j++)
          if ((k >> j) & 1)
            score[i][k] += tscore[j];
      }
      sort(score[i], score[i] + 8);
    }
    for (int i = 0; i < n; i++)
      cin >> ran[i];
    int ans;
    if ((ans = solve()) >= 0) {
      int an = ans % 100;
      ans /= 100;
      printf("%d.%02d\n", ans, an);
    } else
      printf("No solution\n");
  }
  return 0;
}