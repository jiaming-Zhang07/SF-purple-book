#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 60000;
struct Node {
  string s;
  int lef, righ;
  bool operator<(const Node &b) const {
    return tie(s, lef, righ) < tie(b.s, b.lef, b.righ);
  }
} node[maxn];
char *p;
int cnt, kase;
char expr[5 * maxn];
map<Node, int> dist;
int done[maxn];
int parse() {
  int id = cnt++;
  Node &t = node[id];
  t.s = "";
  t.lef = t.righ = -1;
  while (isalpha(*p)) {
    t.s += *p;
    p++;
  }
  if (*p == '(') {
    ++p;
    t.lef = parse();
    ++p;
    t.righ = parse();
    ++p;
  }
  if (dist.count(t)) {
    cnt--;
    return dist[t];
  }
  return dist[t] = id;
}
void print(int v) {
  if (done[v] == kase) {
    cout << v + 1;
    return;
  }
  done[v] = kase;
  cout << node[v].s;
  if (node[v].lef != -1) {
    cout << "(";
    print(node[v].lef);
    cout << ",";
    print(node[v].righ);
    cout << ")";
  }
}
int main() {
  int T;
  cin >> T;
  for (kase = 1; kase <= T; kase++) {
    dist.clear();
    cin >> expr;
    cnt = 0;
    p = expr;
    print(parse());
    cout << "\n";
  }
  return 0;
}