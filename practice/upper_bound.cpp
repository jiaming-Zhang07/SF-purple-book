#include <bits/stdc++.h>
using namespace std;
int bsearch(int *A, int l, int r, int tar) {
  int m;
  while (l < r) {
    m = l + (r - l) / 2;
    if (tar >= A[m])
      l = m + 1;
    else
      r = m;
  }
  return l;
}
