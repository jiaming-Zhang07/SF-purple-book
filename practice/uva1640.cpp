#include <bits/stdc++.h>
using namespace std;
using ll = long long;
char sa[10], sb[10];
int cnt[10];
int main() {
  int a, b;
  while (cin >> a >> b && a) {
    memset(cnt, 0, sizeof(cnt));
    if (b < a)
      swap(a, b);
    int len = to_string(b).size();
    sprintf(sa, "%0*d", len, a);
    sprintf(sb, "%0*d", len, b);
    reverse(sa, sa + len);
    reverse(sb, sb + len);
    vector<int> proa(len), prob(len), taila(len), tailb(len);
    for (int i = len - 1; i > 0; i--) {
      proa[i - 1] = proa[i] * 10 + sa[i] - '0';
      prob[i - 1] = prob[i] * 10 + sb[i] - '0';
    }
    int ten[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    for (int i = 0; i < len - 1; i++) {
      taila[i + 1] = (sa[i] - '0') * ten[i] + taila[i];
      tailb[i + 1] = (sb[i] - '0') * ten[i] + tailb[i];
    }
    for (int j = 0; j < len; j++) {
      int a0 = sa[j] - '0', b0 = sb[j] - '0', pb = prob[j], pa = proa[j], ta = taila[j], tb = tailb[j];
      if (pb - pa >= 1) {
        for (int i = 0; i <= 9; i++)
          cnt[i] += (pb - pa - 1) * ten[j];
        if (!(a0 == 0 && pa == 0))
          cnt[a0] += ten[j] - ta;
        for (int i = a0 + 1; i <= 9; i++)
          cnt[i] += ten[j];
        for (int i = 0; i < b0; i++)
          cnt[i] += ten[j];
        cnt[b0] += tb + 1;
      } else if (sa[j] != sb[j]) {
        for (int i = a0 + 1; i < b0; i++)
          cnt[i] += ten[j];
        if (!(a0 == 0 && pa == 0))
          cnt[a0] += ten[j] - ta;
        cnt[b0] += tb + 1;
      } else
        cnt[a0] += tb - ta + 1;
    }
    cout << cnt[0];
    for (int i = 1; i < 10; i++)
      cout << " " << cnt[i];
    cout << "\n";
  }
  return 0;
}