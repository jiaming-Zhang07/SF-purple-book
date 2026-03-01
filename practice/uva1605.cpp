#include <bits/stdc++.h>
using namespace std;
char country(int i) {
  if (i < 26)
    return 'A' + i;
  return 'a' + i - 26;
}
int main() {
  int n, kase = 0;
  while (cin >> n) {
    if (kase++)
      printf("\n");
    printf("2 %d %d\n", n, n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        printf("%c", country(i));
      printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        printf("%c", country(j));
      printf("\n");
    }
  }
}