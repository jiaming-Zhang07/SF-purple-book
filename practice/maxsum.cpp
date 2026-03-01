#include <bits/stdc++.h>
using namespace std;
int maxsum(int *A, int x, int y) {
  int L, R, v;
  if (y - x == 1)
    return A[x];
  int m = x + (y - x) / 2;
  v = 0;
  R = A[m];
  for (int i = m; i < y; i++)
    R = max(R, v += A[i]);
  v = 0;
  L = A[m - 1];
  for (int i = m - 1; i >= x; i--)
    L = max(L, v += A[i]);
  return max(L + R, max(maxsum(A, x, m), maxsum(A, m, y)));
}
int main() {
  int n;
  cin >> n;
  int A[10];
  for (int i = 0; i < n; i++)
    cin >> A[i];
  printf("%d", maxsum(A, 0, n));
  return 0;
}