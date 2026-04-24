#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;
int ne[maxn];
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  s1 = " " + s1;
  s2 = " " + s2;
  ne[1] = 0;
  for (int i = 2, j = 0; i < s2.size(); i++) {
    while (j && s2[j + 1] != s2[i])
      j = ne[j];
    if (s2[j + 1] == s2[i])
      j++;
    ne[i] = j;
  }
  for (int i = 1, j = 0; i < s1.size(); i++) {
    while (j && (j + 1 == s2.size() || s1[i] != s2[j + 1]))
      j = ne[j];
    if (s1[i] == s2[j + 1])
      j++;
    if (j == s2.size() - 1)
      cout << i - (s2.size() - 1) + 1 << "\n";
  }
  for (int i = 1; i < s2.size(); i++)
    cout << ne[i] << (i == s2.size() - 1 ? "\n" : " ");
  return 0;
}