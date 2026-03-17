#include <bits/stdc++.h>
using namespace std;
int m, n, k;
map<int, double> d[105];
struct stock {
  double v[105];
  string name;
  int s, k;
} st[10];
int decode(int sta, int *h) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    h[i] = sta % 9;
    sta /= 9;
    cnt += h[i];
  }
  return cnt;
}
int encode(int *h) {
  int t = 0;
  for (int i = n - 1; i >= 0; i--)
    t = 9 * t + h[i];
  return t;
}
map<int, int> pre[105];
map<int, int> op[105];
void update(int oldh, int day, int h, double v, int o) {
  if (!d[day].count(h) || v > d[day][h]) {
    d[day][h] = v;
    pre[day][h] = oldh;
    op[day][h] = o;
  }
}
void print(int day, int h) {
  if (day == 0)
    return;
  print(day - 1, pre[day][h]);
  int o = op[day][h];
  if (o == 0)
    cout << "HOLD\n";
  else if (o > 0)
    cout << "BUY " << st[o - 1].name << "\n";
  else
    cout << "SELL " << st[-o - 1].name << "\n";
}
int main() {
  int kase = 0;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  double c;
  while (cin >> c >> m >> n >> k) {
    for (int i = 0; i <= m; i++)
      d[i].clear();
    for (int i = 0; i < n; i++) {
      cin >> st[i].name >> st[i].s >> st[i].k;
      for (int j = 0; j < m; j++)
        cin >> st[i].v[j];
    }
    d[0][0] = c;
    int now[8];
    for (int day = 0; day < m; day++)
      for (auto x : d[day]) {
        int h = x.first;
        double v = x.second;
        update(h, day + 1, h, v, 0);
        int cnt = decode(h, now);
        for (int i = 0; i < n; i++) {
          if (v + 1e-3 >= st[i].v[day] * st[i].s && st[i].k > now[i] && cnt < k) {
            now[i]++;
            update(h, day + 1, encode(now), v - st[i].v[day] * st[i].s, i + 1);
            now[i]--;
          }
          if (now[i] > 0) {
            now[i]--;
            update(h, day + 1, encode(now), v + st[i].v[day] * st[i].s, -i - 1);
            now[i]++;
          }
        }
      }
    if (kase++)
      cout << "\n";
    cout << fixed << setprecision(2) << d[m][0] << "\n";
    print(m, 0);
  }
  return 0;
}