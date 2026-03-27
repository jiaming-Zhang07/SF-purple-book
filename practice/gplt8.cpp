#include <bits/stdc++.h>
using namespace std;
struct team {
  int f[20], sumf, maxac, maxf, acn;
  bool ac[20];
  bool operator<(const team &other) const {
    if (acn != other.acn)
      return acn > other.acn;
    return sumf < other.sumf;
  }
  void rev() {
    swap(sumf, maxf);
    swap(acn, maxac);
  }
} a[100005];
int cnt[305];
int main() {
  int n, m, T, L, S;
  cin >> n >> m >> T >> L >> S;
  for (int i = 0; i < S; i++) {
    int id, t, pro;
    string s;
    cin >> id >> t >> pro >> s;
    if (a[id].ac[pro])
      continue;
    if (s == "Rejected") {
      a[id].f[pro]++;
    } else if (s == "?") {
      a[id].maxac++;
      a[id].ac[pro] = true;
      a[id].maxf += t + a[id].f[pro] * 20;
    } else {
      a[id].ac[pro] = true;
      a[id].acn++;
      a[id].maxac++;
      a[id].sumf += t + a[id].f[pro] * 20;
      a[id].maxf += t + a[id].f[pro] * 20;
    }
  }
  int te;
  cin >> te;
  a[te].rev();
  int num = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] < a[te])
      num++;
  cout << num + 1 << " ";
  num = 0;
  a[te].rev();
  for (int i = 1; i <= n; i++)
    if (i != te) {
      a[i].rev();
      if (a[i] < a[te])
        num++;
    }
  cout << num + 1 << "\n";
  return 0;
}