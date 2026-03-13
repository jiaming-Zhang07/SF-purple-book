#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    int loc = 0;
    printf("0 ");
    if (c % 3 == 0) {
      for (int i = 0; i < c / 3; i++)
        printf("%d ", loc += 3);
      printf("%d ", loc += 1);
      for (int i = 0; i < c / 3; i++)
        printf("%d ", loc -= 3);
      printf("%d ", loc += 1);
      for (int i = 0; i < c / 3; i++)
        printf("%d ", loc += 3);
      a -= 2;
    } else if (c % 3 == 1) {
      for (int i = 0; i < c / 3 + 1; i++)
        printf("%d ", loc += 3);
      printf("%d ", loc -= 2);
      for (int i = 0; i < c / 3; i++)
        printf("%d ", loc -= 3);
      printf("%d ", loc += 1);
      for (int i = 0; i < c / 3; i++)
        printf("%d ", loc += 3);
      printf("%d ", loc += 2);
      a -= 1;
      b -= 2;
    } else {
      for (int i = 0; i < c / 3 + 1; i++)
        printf("%d ", loc += 3);
      printf("%d ", loc -= 1);
      for (int i = 0; i < c / 3; i++)
        printf("%d ", loc -= 3);
      printf("%d ", loc -= 1);
      for (int i = 0; i < c / 3 + 1; i++)
        printf("%d ", loc += 3);
      a -= 2;
    }
    for (int i = 1; i < a; i++)
      printf("%d ", loc += 1);
    if (b & 1) {
      for (int i = 0; i < b / 2 + 1; i++)
        printf("%d ", loc += 2);
      printf("%d%s", loc -= 1, b / 2 == 0 ? "\n" : " ");
      for (int i = 0; i < b / 2; i++)
        printf("%d%s", loc -= 2, i == b / 2 - 1 ? "\n" : " ");
    } else {
      for (int i = 0; i < b / 2; i++)
        printf("%d ", loc += 2);
      printf("%d ", loc += 1);
      for (int i = 0; i < b / 2; i++)
        printf("%d%s", loc -= 2, i == b / 2 - 1 ? "\n" : " ");
    }
  }
  return 0;
}