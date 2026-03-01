#include <bits/stdc++.h>
using namespace std;
void merge_sort(int *A, int x, int y, int *T) {
  if (y - x > 1) {
    int m = x + (y - x) / 2;
    merge_sort(A, x, m, T);
    merge_sort(A, m, y, T);
    int i = x, p = x, q = m;
    while (p < m || q < y) {
      if (q >= y || (p < m && A[p] <= A[q]))
        T[i++] = A[p++];
      else
        T[i++] = A[q++];
    }
    for (int i = x; i < y; i++)
      A[i] = T[i];
  }
}
