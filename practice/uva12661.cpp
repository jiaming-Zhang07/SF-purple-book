#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, s, t;
struct edge {
  ll v, a, b, tt, ne;
} e[50005];
ll tot = 1, h[305], d[305], done[305];
void add(int u, int v, int a, int b, int tt) {
  e[++tot] = {v, a, b, tt, h[u]};
  h[u] = tot;
}
struct sta {
  ll u, t;
  bool operator<(const sta &b) const {
    return t > b.t;
  }
};
ll dij() {
  memset(d, 0x3f, sizeof(d));
  memset(done, 0, sizeof(done));
  priority_queue<sta> pq;
  pq.push({s, 0});
  d[s] = 0;
  while (pq.size()) {
    auto [u, tt] = pq.top();
    pq.pop();
    if (done[u])
      continue;
    done[u] = 1;
    for (int i = h[u]; i; i = e[i].ne) {
      int v = e[i].v, a = e[i].a, b = e[i].b, lef = tt % (a + b), tempt = e[i].tt, tempd = d[u];
      if (lef + tempt <= a)
        tempd += tempt;
      else
        tempd += a + b - lef + tempt;
      if (tempd < d[v]) {
        d[v] = tempd;
        pq.push({v, tempd});
      }
    }
  }
  return d[t];
}
int main() {
  int kase = 0;
  while (cin >> n >> m >> s >> t) {
    memset(h, 0, sizeof(h));
    tot = 1;
    int u, v, a, b, tt;
    for (int i = 0; i < m; i++) {
      cin >> u >> v >> a >> b >> tt;
      if (tt <= a)
        add(u, v, a, b, tt);
    }
    printf("Case %d: %lld\n", ++kase, dij());
  }
  return 0;
}