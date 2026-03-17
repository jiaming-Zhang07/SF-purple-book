#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n;
char s[maxn];
int d[maxn][maxn];
bool match(int i, int j) {
  return (s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']');
}
void print(int i, int j) {
  if (i > j)
    return;
  if (i == j) {
    if (s[i] == '(' || s[i] == ')') {
      printf("()");
    } else
      printf("[]");
    return;
  }
  if (match(i, j) && d[i][j] == d[i + 1][j - 1]) {
    printf("%c", s[i]);
    print(i + 1, j - 1);
    printf("%c", s[j]);
    return;
  }
  for (int k = i; k < j; k++)
    if (d[i][j] == d[i][k] + d[k + 1][j]) {
      print(i, k);
      print(k + 1, j);
      return;
    }
}
void get() {
  fgets(s, maxn, stdin);
}
int main() {
  int T;
  get();
  sscanf(s, "%d", &T);
  while (T--) {
    get();
    get();
    n = strlen(s);
    while (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r'))
      n--;
    for (int i = 0; i < n; i++) {
      d[i][i] = 1;
      d[i + 1][i] = 0;
    }
    for (int i = n - 2; i >= 0; i--)
      for (int j = i + 1; j < n; j++) {
        d[i][j] = n;
        if (match(i, j))
          d[i][j] = d[i + 1][j - 1];
        for (int k = i; k < j; k++)
          d[i][j] = min(d[i][k] + d[k + 1][j], d[i][j]);
      }
    print(0, n - 1);
    printf("\n");
    if (T)
      printf("\n");
  }
  return 0;
}